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

    /*
     * 2275. 按位与结果大于零的最长组合
     *
     * e.g.
     * candidates = [16,17,71,62,12,24,14]
     * -> 4
     * 组合 [16,17,62,24] 的按位与结果是 16 & 17 & 62 & 24 = 16 > 0
     */
    int largestCombination(vector<int> &candidates) {
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

    void process(vector<int> &acc, int u) {
        int i = 0;
        while (u > 0) {
            int t = u % 2;
            if (t == 1) {
                acc[i]++;
                u -= 1;
            }
            u /= 2;
            i++;
        }
    }

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