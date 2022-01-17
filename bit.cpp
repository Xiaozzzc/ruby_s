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
#include "learning.cpp"
#include "binarySearch.cpp"
#include "linkedLst.cpp"

using namespace std;

class Bit {
public:
    /*
     * 5978. 统计追加字母可以获得的单词数
     */
    int wordCount0(vector<string>& startWords, vector<string>& targetWords) {
        set<int> iSet;
        for (auto s: startWords) {
            iSet.insert(makeInt(s));
        }
        int ans = 0;
        for (auto s: targetWords) {
            int it = makeInt(s);
            for (int i = 0; i < s.size(); i++) {
                int t = it - (1 << (s[i] - 'a'));
                if (iSet.find(t) != iSet.end()) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }

    int makeInt(string s) {  // s中字符不重复，将string转化为int
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans |= 1 << (s[i] - 'a');
        }
        return ans;
    }
};