#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


class DPPalindrome {
public:
    /*
     * 5. Longest Palindromic String
     * return the longest palindromic substring in s
     *
     * e.g.
     * s = "babad"
     * -> "bab"
     * s = "cbbd"
     * -> "bb"
     */
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));  // dp[i][j] = true means substring [l, r] is palindrome
        int l = 0, r = 0;
        int max = 0;
        //   j
        // i . T T T T T
        //   . . T T T T
        //   . . . T T T
        //   . . x . T T
        //   . *
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                // substring [i, j]
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

    int longestPalindrome(string s, string t) {
        reverse(t.begin(), t.end());
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        vector<int> prefixS(n + 1); // length of maximum palindrome substring starting at prefixS[i]
        vector<vector<bool>> dpS(n, vector<bool>(n));
        // stores if s[i...j] is palindromic or not, needed for prefixS computation
        vector<int> prefixT(m + 1);
        // length of maximum palindromic substring starting at prefixT[j]. Note now T is reverse of original T
        vector<vector<bool>> dpT(m, vector<bool>(m));
        // prefixS and prefixT is used to incorporate the middle palindrome
        // since any solution will have structure X + middle + reverse of X

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || dpS[i + 1][j - 1])) {
                    // if s[i+1...j-1] is palindromic and s[i] == s[j] then s[i...j] is also palindromic
                    dpS[i][j] = true;
                    prefixS[i] = max(prefixS[i], j - i + 1);
                }
            }
            ans = max(ans, prefixS[i]);
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = i; j < m; j++) {
                if (t[i] == t[j] && (j - i < 2 || dpT[i + 1][j - 1])) {
                    dpT[i][j] = true;
                    prefixT[i] = max(prefixT[i], j - i + 1);
                }
            }
            ans = max(ans, prefixT[i]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                ans = max(ans, 2 * dp[i][j] + max(prefixS[i], prefixT[j]));
            }
        }
        return ans;
    }
};