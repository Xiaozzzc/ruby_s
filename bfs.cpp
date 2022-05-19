#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;

class BFS {
public:
    void doNothing(void);
    /*
     * 2146. 价格范围内最高排名的 K 样物品
     * 给出grid，其中 0 是墙无法通过，1 是梯子可通过，其余是物品，求排名最高的 k 样物
     * 起点 start[], 价格区间 pricing[], 物品排名规则：
     * 1. 优先选距离近的
     * 2. 价格低的
     * 3. x 坐标小的
     * 4. y 坐标小的
     * 求排名前 k 的物品
     *
     * 分层 BFS
     */
    int dirs[4][2] = {{-1, 0},
                      {1,  0},
                      {0,  -1},
                      {0,  1}};  // 方向

    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k) {
        vector<vector<int>> ans;
        int m = grid.size(), n = grid[0].size();
        int low = pricing[0], high = pricing[1];
        int sx = start[0], sy = start[1];
        vector<vector<int>> vis(m, vector<int>(n));  // 初始化 mp * n 数组
        vis[sx][sy] = 1;
        vector<vector<int>> q = {{sx, sy}};  // 直接这样初始化队列
        while (!q.empty()) { // 分层 BFS
            // 此时 q 内所有元素到起点的距离均相同
            sort(q.begin(), q.end(), [&](auto &a, auto &b) {
                int pa = grid[a[0]][a[1]], pb = grid[b[0]][b[1]];  // 价格从小到大，相同价格的话按方位排序
                return pa < pb || pa == pb && a < b;  // (x,y) x小在前，如果x相同则y小在前
            });
            for (auto &p: q) {
                if (low <= grid[p[0]][p[1]] && grid[p[0]][p[1]] <= high) {
                    ans.emplace_back(p);
                    if (ans.size() == k) {
                        return ans;
                    }
                }
            }
            vector<vector<int>> qq;  // 新的一个队列
            for (auto &p: q) {
                for (auto &d: dirs) {
                    int x = p[0] + d[0], y = p[1] + d[1];
                    if (0 <= x && x < m && 0 <= y && y < n && !vis[x][y] && grid[x][y]) {
                        vis[x][y] = true;
                        vector<int> p = {x, y};
                        qq.emplace_back(p);
                    }
                }
            }
            q = move(qq);
        }
        return ans;
    }

    /*
     * LCP 09. 最小跳跃次数
     * 给定一个数组 int[] jump，位于数组第i位置可以向前跳 i 格，或者跳到 下标小于 i 的任意一格
     * 小球初始位于 0 位置，求最少跳几次能跳出数组（i >= jump.length）
     * e.g.
     * jump = [2, 5, 1, 1, 1, 1]
     * -> 3
     *
     * BFS最短路径
     */
    int minJump(vector<int>& jump) {
        int n = jump.size();
        queue<pair<int, int> > q; // 当前位置 idx，按动次数 d
        // 初始值：编号为 0 的弹簧  按动次数 为0
        q.emplace(0, 0);
        // 某一个位置已经被扩展过了，就不需要被再次扩展：BFS最短路
        // 记录某个位置是否被扩展过：seen
        vector<bool> seen(n, false);
        seen[0] = true;
        int preidx = 1;
        while (!q.empty()) {
            auto[idx, d] = q.front();  // 不用一轮一轮的，只用记录 <id, 轮数> 即可
            q.pop();

            // 向右扩展
            int next = idx + jump[idx];
            if (next > n - 1) {
                // 跳出弹簧
                // BFS 最短路
                return d + 1;
            }
            if (!seen[next]) {
                seen[next] = true;
                q.emplace(next, d + 1);
            }
            while (preidx < idx) {
                // 最多只会遍历一遍全部位置 ：O(n)
                if (!seen[preidx]) {
                    seen[preidx] = true;
                    q.emplace(preidx, d + 1);
                }
                preidx++;
            }
        }

        // 遍历完整个队列，还未返回，说明无法到达
        return -1;
    }
};