#include "dfs.cpp"
#include "linkedLst.cpp"
#include "utils.cpp"
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

class subarray {
public:
    // A subarray is a contiguous sequence of elements within an array.
    // nums = [1,2,3,4,5,6,7,8]
    // -> [1,2,3], [3,4,5], [4,5,6,7], [7,8]
    //
    // A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
    // nums = [1,2,3,4,5,6,7,8]
    // -> [1,3,4], [2,3,7], [5,6,7], [7,8]


    // 2537. Count the Number of Good Subarrays
    // A subarray is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j]
    // sliding window
    //
    // nums = [3,1,4,3,2,2,4], k = 2
    // -> 4
    // - [3,1,4,3,2,2] that has 2 pairs.
    // - [3,1,4,3,2,2,4] that has 3 pairs.
    // - [1,4,3,2,2,4] that has 2 pairs.
    // - [4,3,2,2,4] that has 2 pairs.
    //
    // problem of pairs
    // [3] 0
    // [3,3] 0+1 pairs
    // [3,3,3] 0+1+2 pairs
    // [3,3,3,3] 0+1+2+3 pairs
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // mp[u] is the number of times u appears in the window
        long long ans = 0;
        int n = nums.size();
        int left = 0, cnt = 0;
        for (int right = 0; right < n; right++) {
            cnt += mp[nums[right]];
            mp[nums[right]]++;
            while (cnt >= k) {
                mp[nums[left]]--;
                cnt -= mp[nums[left]];
                left++;
            }
            // at this time, [left, i] isn't qualified
            ans += left;
        }
        return ans;
    }

    // 2302. Count Subarrays With Score Less Than K
    // A good subarray is (sum of elements) * (num of elements) < k
    // given a list, return the number of good subarray
    // sliding window
    //
    // nums = [2,1,4,3,5], k = 10
    // -> 6
    // [2], [1], [4], [3], [5], [2, 1]
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        int left = 0;
        long long sum = 0;
        // right side moving forward, if illegal, left side move forward until reaching right
        for (int right = 0; right < n; right++) {
            // right move forward
            sum += nums[right];
            while (sum * (right - left + 1) >= k) {
                // if illegal
                sum -= nums[left];
                left++; // left move forward
            }
            // now it's all legal
            // all subarray that ends with right are good ones
            // [left, right], [left + 1, right], ... , [right - 1, right], [right, right]
            ans += right - left + 1;
        }
        return ans;
    }

    // 2962. Count Subarrays Where Max Element Appears at Least K Times
    // sliding windows
    // nums = [1,3,2,3,3], k = 2
    // -> 6
    // [1,3,2,3], [3,2,3], [1,3,2,3,3], [3,2,3,3], [2,3,3], [3,3]
    // nums = [1,4,2,1], k = 3
    // -> 0
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int left = 0;
        int mxNum = 0;
        int mx = 0;
        for (int u : nums) {
            mx = max(u, mx);
        }
        for (int right = 0; right < n; right++) {
            // sliding windows
            if (nums[right] == mx) {
                mxNum++;
            }
            while (mxNum == k) {
                // ans += n - right;
                if (nums[left++] == mx) {
                    mxNum--;
                }
            }
            ans += left;
        }
        return ans;
    }

    // 763. Partition Labels
    // partition s into as many parts as possible, each letter belongs to only one part
    // return the number of letters in each part
    // eg.
    // s = "ababcbacadefegdehijhklij"
    // -> [9, 7, 8]
    // "ababcbaca", "defegde", "hijhklij"
    vector<int> partitionLabels(string s) {
        map<char, int> lastOcc;
        for (int i = 0; i < s.size(); i++) {
            lastOcc[s[i]] = i;
        }
        int maxLastOcc = 0;
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            maxLastOcc = max(maxLastOcc, lastOcc[s[i]]);
            cnt++;
            if (maxLastOcc == i) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        return ans;
    }

    // 2251. Put Marbles in Bags
    // Split weights into bags, calculate the max costs difference between bags
    // the cost of a bag is sum of the first marble plus sum of the last marble
    // weights = [1,3,5,1], k = 2
    // -> 4
    // min [1] [3,5,1] -> costs 1 + 1 + (3 + 1) = 6
    // max [1,3] [5,1] -> costs 1 + 3 + 5 + 1 = 10
    // max - min = 4
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) return 0;
        vector<int> sum2;
        for (int i = 0; i < weights.size() - 1; i++) {
            sum2.push_back(weights[i] + weights[i + 1]);
        }
        sort(sum2.begin(), sum2.end());
        // sum of the first (k-1) elements of sum2
        long long min = 0;
        for (int i = 0; i < k - 1; i++) {
            min += sum2[i];
        }
        long long max = 0;
        // sum of the last (k - 1) elements of sum2
        int cnt = k - 1;
        for (int i = sum2.size() - 1; i >= 0; i--) {
            if (cnt == 0) break;
            max += sum2[i];
            cnt--;
        }
        return max - min;
    }

    // 2780. Minimum Index of a Valid Split
    // x is dominant in array if "more than half" of the array is x
    // given a array nums with one dominant element
    // return the smallest index to split it into 2 subarray to make both subarray dominant
    // nums = [1,2,2,2]
    // -> 2 [1,2,2] [2]
    // nums = [2,1,3,1,1,1,7,1,2,1]
    // -> 4 [2,1,3,1,1] [1,7,1,2,1]
    // nums = [3,3,3,3,7,2,2]
    // -> -1
    int minimumIndex(vector<int>& nums) {
        pair<int, int> maxPair(0, 0);
        map<int, int> mp;
        for (int u : nums) {
            mp[u]++;
            int num = mp[u];
            if (num > maxPair.second) {
                maxPair.first = u;
                maxPair.second = num;
            }
        }
        if (maxPair.second <= (nums.size() + 1) / 2) {
            return -1;
        }
        int b = maxPair.first; // the target number
        int t = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == b) {
                t++;
            }
            // by index i there are t times occurrence
            if (t > (i + 1) / 2) {
                return i;
            }
        }
        return -1;
    }

    // 594. Longest Harmonious Subsequence
    // Harmonious array as an array where max_value - min_value = 1
    // Return the length of its longest harmonious subsequence
    // [1,3,2,2,5,2,3,7]
    // -> 5, [3,2,2,2,3]
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int u : nums) {
            mp[u]++;
        }
        int mx = 0;
        for (auto& [k, v] : mp) {
            // iterate map
            if (mp.find(k - 1) != mp.end()) {
                // map.find
                // find a key in map
                mx = max(mx, mp[k - 1] + v);
            } else if (mp.count(k + 1)) {
                // another way
                mx = max(mx, mp[k + 1] + v);
            }
        }
        return mx;
    }
};
