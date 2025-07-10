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
    // 594. Longest Harmonious Subsequence
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int u : nums) {
            mp[u]++;
        }
        int mx = 0;
        for (auto& [k, v] : mp) {
            if (mp.find(k - 1) != mp.end()) {
                // find a key in map
                mx = max(mx, mp[k - 1] + v);
            } else if (mp.count(k + 1)) {
                // another way
                mx = max(mx, mp[k + 1] + v);
            }
        }
        return mx;
    }

    // 1498. Number of Subsequences That Satisfy the Given Sum Condition
    // return the number of non-empty sequences which min + max <= target
    // nums = [3,5,6,7], target = 9
    // -> 4
    // [3], [3,5], [3,6], [3,5,6]
    //
    // nums = [2,3,3,4,6,7], target = 12
    // -> 61
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7; // how to deal with mod?
        int res = 0;
        sort(nums.begin(), nums.end());
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod; // because each element can be out of range
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                res = (res + power[r - l]) % mod; // and the sum of elements can be out of range
                l++;
            } else {
                r--;
            }
        }
        return res;
    }

    // how to deal with mod? The wrong way
    int numSubseq1(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int res = 0;
        sort(nums.begin(), nums.end());
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                res += pow(2, r - l); // Here, not only res, but also pow(2, r - l) can easily go out of range
                l++;
            } else {
                r--;
            }
        }
        return res;
    }

    // 2311. Longest Binary Subsequence Less Than or Equal to K
    // This question looks confusing but actually it's not. Just think further.
    // s = "1001010", k = 5
    // -> 5
    // can be "00010", "00100", "00101" all 5 characters
    // s = "00101001", k = 1
    // -> 6
    int longestSubsequence(string s, int k) {
        int cnt0 = 0;
        for (char c : s) {
            if (c == '0') {
                cnt0++;
            }
        }
        int cnt1 = 0;
        int n = s.size();
        long long sum = 0, pow = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (sum + pow > k) break;
                sum += pow;
                cnt1++;
            }
            pow <<= 1;
            if (pow > k) break; // necessary bc binary number can easily be bigger than long long
        }
        return cnt0 + cnt1;
    }

    // 78. Subsets
    // nums = [1,2,3]
    // -> [],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> ans;
        dfs(nums, ans, vec, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& vec, int idx) {
        // keep ans inside
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
