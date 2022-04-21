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


class Solution {
public:

    int longestPath(vector<int> &parent, string s) {
        // 从后往前
        int n = parent.size();
        vector<vector<int>> ps(n, vector<int>(2));  // vector<int>(n) 只关心最长的两个
        int ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            int p = parent[i];
            vector<int>& cur = ps[i];
            if (p != -1 && s[p] == s[i]) {
                ret = max(ret, cur[0] + cur[1] + 1);
                continue;
            }
            if (p == -1) {
                ret = max(ret, cur[0] + cur[1] + 1);
                continue;
            }
            vector<int>& prt = ps[p];
            int report = cur[0] + 1;
            if (report > prt[0]) prt[0] = report;
            else if (report > prt[1]) prt[1] = report;

            ret = max(ret, cur[0] + cur[1] + 1);
        }
        return ret;
    }

    int maxTrailingZeros(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> grid2(m, vector<int>(n));
        vector<vector<int>> grid5(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = grid[i][j];
                int n2 = 0, n5 = 0;
                while (cur % 2 == 0 && cur > 0) {
                    n2++;
                    cur /= 2;
                }
                while (cur % 5 == 0 && cur > 0) {
                    n5++;
                    cur /= 5;
                }
                grid2[i][j] = n2;
                grid5[i][j] = n5;
            }
        }
        vector<vector<pair<int, int>>> gridUp(m, vector<pair<int, int>>(n));
        vector<vector<pair<int, int>>> gridDown(m, vector<pair<int, int>>(n));
        vector<vector<pair<int, int>>> gridLeft(m, vector<pair<int, int>>(n));
        vector<vector<pair<int, int>>> gridRight(m, vector<pair<int, int>>(n));
        for (int i = 0; i < m; i++) {
            int sum2 = 0, sum5 = 0;
            for (int j = 0; j < n; j++) {
                sum2 += grid2[i][j];
                sum5 += grid5[i][j];
                gridRight[i][j] = pair<int, int>(sum2, sum5);
            }
        }
        for (int i = 0; i < m; i++) {
            int sum2 = 0, sum5 = 0;
            for (int j = n - 1; j >= 0; j--) {
                sum2 += grid2[i][j];
                sum5 += grid5[i][j];
                gridLeft[i][j] = pair<int, int>(sum2, sum5);
            }
        }
        for (int j = 0; j < n; j++) {
            int sum2 = 0, sum5 = 0;
            for (int i = 0; i < m; i++) {
                sum2 += grid2[i][j];
                sum5 += grid5[i][j];
                gridDown[i][j] = pair<int, int>(sum2, sum5);
            }
        }
        for (int j = 0; j < n; j++) {
            int sum2 = 0, sum5 = 0;
            for (int i = m - 1; i >= 0; i--) {
                sum2 += grid2[i][j];
                sum5 += grid5[i][j];
                gridUp[i][j] = pair<int, int>(sum2, sum5);
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pair<int, int> right = gridRight[i][j];
                pair<int, int> left = gridLeft[i][j];
                pair<int, int> up = gridUp[i][j];
                pair<int, int> down = gridDown[i][j];
                int u2, u5, u;

                u2 = right.first + up.first;
                u5 = right.second + up.second;
                u2 -= grid2[i][j];
                u5 -= grid5[i][j];
                u = min(u2, u5);
                res = max(res, u);

                u2 = right.first + down.first;
                u5 = right.second + down.second;
                u2 -= grid2[i][j];
                u5 -= grid5[i][j];
                u = min(u2, u5);
                res = max(res, u);

                u2 = left.first + up.first;
                u5 = left.second + up.second;
                u2 -= grid2[i][j];
                u5 -= grid5[i][j];
                u = min(u2, u5);
                res = max(res, u);

                u2 = left.first + down.first;
                u5 = left.second + down.second;
                u2 -= grid2[i][j];
                u5 -= grid5[i][j];
                u = min(u2, u5);
                res = max(res, u);
            }
        }
        return res;
    }

    int minimumRounds(vector<int> &tasks) {
        map<int, int> mp;
        for (int u: tasks) {
            mp[u]++;
        }
        int res = 0;
        for (auto&[k, v]: mp) {
            if (v == 1) return -1;
            res += cal(v);
        }
        return 0;
    }

    int cal(int u) {
        int t = u % 3;
        if (t == 0) {
            return u / 3;
        }
        if (t == 1) {
            return (u - 4) / 3 + 2;
        }
        return (u - 2) / 3 + 1;
    }

    string digitSum(string s, int k) {
        while (s.size() > k) {
            s = handle(s, k);
        }
        return s;
    }

    string handle(string s, int k) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; i += k) {
            string s1 = s.substr(i, k);
            int n1 = s1.size();
            int t = 0;
            for (int j = 0; j < n1; j++) {
                t += s1[j] - '0';
            }
            res += to_string(t);
        }
        return res;
    }

    int maximumProduct(vector<int> &nums, int k) {
        //这题最关键的看出是最小的加1 其次用优先队列更快
        priority_queue<int, vector<int>, greater<int>> pq;  // 最小堆 升序的优先队列

        for (auto i: nums) {
            pq.push(i);
        }

        for (int i = 0; i < k; i++) {
            int tmp = pq.top();
            pq.pop();
            tmp++;
            pq.push(tmp);
        }

        long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % 100000007;
            pq.pop();
        }

        return ans;
    }

    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
        // 初始化一个大小为 18 的数组，初始值为 INT_MAX / 2
        // 除二是防止下面计算状态转移时溢出
        // minSec[x] 表示 完成 x 轮，不换轮胎 所需要的最少时间
        vector<int> minSec(18, INT_MAX / 2);
        for (auto &tire: tires) {
            long time = tire[0];
            for (int x = 1, sum = 0; time <= changeTime + tire[0]; ++x) {
                sum += time;
                minSec[x] = min(minSec[x], sum);
                time *= tire[1];
            }
        }

        vector<int> f(numLaps + 1, INT_MAX);  // f[i] 表示跑 i 圈所需要的最少时间
        f[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            // f[i] 最多从 f[i - 17] 进化而来
            for (int j = 1; j <= min(17, i); ++j)
                f[i] = min(f[i], f[i - j] + minSec[j]);
            f[i] += changeTime;
        }
        return f[numLaps];
    }
};