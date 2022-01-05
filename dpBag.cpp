#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


class DPBag {
public:
    /*
     * 279. 完全平方数
     * 给定一个数 n，求 n 最多能由几个完全平方数相加得到，返回其个数
     *
     * e.g.
     * n = 12
     * 12 = 4 + 4 + 4
     * -> 3
     *
     * n = 13
     * 13 = 4 + 9
     * -> 2
     *
     */
    int numSquares(int n) {
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            int cur = i * i;
            for (int j = cur; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - cur] + 1);
            }
        }
        return dp[n];
    }
};