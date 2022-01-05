#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


class DPPalSeq {
public:
    /*
     * 5. 最长回文子串
     */
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n);
        for (int i = 0; i < n; i++) {
            vector<bool> t(n, true);
            dp[i] = t;
        }
        int l = 0, r = 0;
        int max = 0;
        for (int j = 0; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j]) {
                    if (j - i > max) {
                        max = j - i;
                        l = i;
                        r = j;
                    }
                }
            }
        }
        // [l, r + 1)
        return s.substr(l, r + 1 - l);
    }
};