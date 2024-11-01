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