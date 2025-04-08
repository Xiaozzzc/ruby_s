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

class subset {
public:
    // 78. Subsets
    // nums = [1,2,3]
    // -> [],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> ans;
        dfs(nums, ans, vec, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& vec, int idx) {  // keep ans inside
        if (idx == nums.size()) {
            ans.emplace_back(vec); // autonomously create a new vector
            return;
        }
        // not picking nums[idx]
        dfs(nums, ans, vec, idx + 1);

        // picking nums[idx]
        vec.push_back(nums[idx]);
        dfs(nums, ans, vec, idx + 1);
        vec.pop_back();
    }

    // 368. Largest Divisible Subset
    // nums = [1,2,3,4,6,8]
    // -> [1,2,4,8]
    // [4,8,10,240] -> [4,8,240]
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mx = 1;
        int maxIdx = 0;
        vector<int> dp(n, 1); // dp[i]: length of largest subset ending at nums[i]
        vector<int> prev(n, -1); // prev[i]: index of previous element in the subset
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                        if (dp[i] > mx) {
                            mx = dp[i];
                            maxIdx = i;
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while (maxIdx >= 0) {
            ans.push_back(nums[maxIdx]);
            maxIdx = prev[maxIdx];
        }
        return ans;
    }
};
