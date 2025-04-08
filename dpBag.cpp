#include "dfs.cpp"
#include "linkedLst.cpp"
// #include "utils.cpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class dpBag {
public:
    /**
     * --------------------------------------- 01背包 ---------------------------------------
     *
     * 0-1 背包问题，不可重复选<br>
     *
     * 选取物品总量 不能超过 规定数量，问最多物品数<br>
     * 选取物品总量 恰好等于 规定数量，问最小物品数<br>
     * 选取物品总量 恰好等于 规定数量，问可行性<br>
     * 选取物品总量 恰好等于 规定数量，问方案总数<br>
     * 选取物品总量 恰好等于 规定数量，问最小物品数量
     */

    // 416. Partition Equal Subset Sum
    // return true if there exists a subset that sums to half of the total sum
    //
    // e.g.
    // nums = [1,5,11,5]
    // -> true [1,5,5] [11]
    // nums = [1,2,3,5]
    // -> false
    bool canPartition(vector<int>& nums) {
        int sum2 = accumulate(nums.begin(), nums.end(), 0);
        if (sum2 % 2 == 1) return false;
        int sum = sum2 / 2;
        vector<bool> f(sum + 1); // f[i] = true means there are subset that sums i
        f[0] = true;
        for (int u : nums) {
            for (int i = sum; i >= 0; i--) {
                // dp from end to front
                f[i] = f[i] || f[i - u];
                if (f[sum]) {
                    return true;
                }
            }
        }
        return f[sum];
    }

    bool canPartition1(vector<int>& nums) {
        int sum2 = accumulate(nums.begin(), nums.end(), 0);
        if (sum2 % 2 == 1) return false;
        int sum = sum2 / 2;
        vector<bool> f(sum + 1); // f[i] = true means there are subset that sums i
        f[0] = true;
        for (int u : nums) {
            vector<int> update;
            for (int i = 0; i < f.size(); i++) {
                // dp from front to end, use vector<int> update to save temporary results
                if (f[i]) {
                    if (i + u == sum) {
                        return true;
                    }
                    update.push_back(i + u);
                }
            }
            for (int ud : update) {
                if (ud <= f.size()) {
                    f[ud] = true;
                }
            }
        }
        return f[sum];
    }

    // 279. Perfect Squares
    // return the least number of perfect square numbers that sum to n
    // perfect square numbers are 1, 4, 9, 16, 25...
    //
    // e.g.
    // n = 12
    // -> 3, 12 = 4 + 4 + 4
    // n = 13
    // -> 2, 13 = 4 + 9
    int numSquares(int n) {
        vector<int> dp(n + 1, 0x3f3f3f3f); // dp[i] means the least number of psn that sums to i
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
