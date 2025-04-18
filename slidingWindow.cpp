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

class slidingWindow {
public:
    // 2537. Count the Number of Good Subarrays
    // A subarray is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j]
    // e.g.
    // nums = [3,1,4,3,2,2,4], k = 2
    // -> 4
    // - [3,1,4,3,2,2] that has 2 pairs.
    // - [3,1,4,3,2,2,4] that has 3 pairs.
    // - [1,4,3,2,2,4] that has 2 pairs.
    // - [4,3,2,2,4] that has 2 pairs.
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mmp;
        long long ans = 0;
        int n = nums.size();
        int left = 0;
        // k -> how many more pairs needed in current windows
        for (int i = 0; i < n; i++) {
            k -= mmp[nums[i]];
            mmp[nums[i]]++;
            while (k <= 0) {
                mmp[nums[left]]--;
                k += mmp[nums[left]];
                left++;
            }
            // at this time, [left, i] isn't qualified
            ans += left;
        }
        return ans;
    }
};