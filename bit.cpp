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
#include "solution.cpp"
#include "binarySearch.cpp"
#include "linkedLst.cpp"

using namespace std;


class Bit {
public:
    // 2275. largest combination with Bitwise AND greater than zero
    void process(vector<int>& acc, int u) {
        // turn integer into binary
        int i = 0;
        while (u > 0) {
            if (u % 2 == 1) {
                acc[i]++;
            }
            u /= 2; // u >>= 1
            i++;
        }
    }

    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<int> acc(100, 0);
        for (int i = 0; i < n; ++i) {
            process(acc, candidates[i]);
        }
        int mx = 0;
        for (int i = 0; i < 100; ++i) {
            mx = max(mx, acc[i]);
        }
        return mx;
    }

    /*
     * 2135. count-words-obtained-after-adding-a-letter
     */
    int sToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            ret |= 1 << (s[i] - 'a');
        }
        return ret;
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<int> st;
        int ans = 0;
        for (auto s : startWords) {
            st.insert(sToInt(s));
        }
        for (auto s : targetWords) {
            int t = sToInt(s);
            for (int i = 0; i < s.size(); i++) {
                int t1 = t - (1 << (s[i] - 'a'));
                if (st.count(t1)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }

    // 3011. Find if array can be sorted
    bool canSortArray(vector<int>& nums) {
        pair<int, int> pre = {INT_MIN, INT_MIN}, cur; // {min, max}, define a pair {}
        int preBit = -1;
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            int b = __builtin_popcount(t); // bit count function
            if (b != preBit) {
                // move on
                if (cur.first < pre.second) {
                    return false;
                }
                pre = cur;
                cur = {t, t};
                preBit = b;
            } else {
                cur.first = min(t, cur.first);
                cur.second = max(t, cur.second);
            }
        }
        return pre.second < cur.first;
    }

    // 1072. flip-columns-for-maximum-number-of-equal-rows
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp; // define empty map
        for (auto& row : matrix) {
            string pattern; // define empty string
            if (row[0] == 0) {
                for (int t : row)
                    pattern += to_string(t);
            } else {
                for (int t : row) {
                    pattern += to_string(t ^ 1); // ^ -- bitwise XOR
                }
            }
            mp[pattern]++;
        }
        int ans = 0;
        for (auto& pair : mp) {
            ans = max(ans, pair.second);
        }
        return ans;
    }
};
