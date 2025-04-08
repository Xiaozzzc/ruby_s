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
};