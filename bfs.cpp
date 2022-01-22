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