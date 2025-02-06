#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;

class str {
public:
    // 1790. Check If One String Swap Can Make String Equal
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        char c1 = '.', c2 = '.';
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (c1 == '.') {
                    c1 = s1[i];
                    c2 = s2[i];
                } else if (cnt > 2) {
                    return false;
                } else if (s1[i] != c2 || s2[i] != c1) {
                    return false;
                }
            }
        }
        if (cnt == 1) return false;
        return true;
    }

    // 1957
    string makeFancyString(string s) {
        char l1 = '.';
        char l2 = '.';
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == l1 && s[i] == l2) {
                continue;
            }
            ans += s[i];
            l2 = l1;
            l1 = s[i];
        }
        return s;
    }

};