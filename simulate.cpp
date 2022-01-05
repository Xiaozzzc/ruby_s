#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


class Simulate {
public:
    /*
     * 2100. 适合打劫银行的日子
     * 你和一群强盗准备打劫银行。给你一个下标从 0 开始的整数数组 security ，其中 security[i] 是第 i 天执勤警卫的数量。日子从 0 开始编号。同时给你一个整数 time 。
     * 如果第 i 天满足以下所有条件，我们称它为一个适合打劫银行的日子：
     * 第 i 天前和后都分别至少有 time 天。
     * 第 i 天前连续 time 天警卫数目都是 递减 的。
     * 第 i 天后连续 time 天警卫数目都是 递增 的。
     *
     * e.g.
     * security = [5,3,3,3,5,6,2], time = 2
     * -> [2,3]
     *
     * security = [1,1,1,1,1], time = 0
     * -> [0,1,2,3,4]
     *
     * security = [1,2,3,4,5,6], time = 2
     * -> []
     */
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int n = security.size();
        vector<int> left(n);  // vector 用作 Java 中的有界数组
        for (int i = 1; i < n; i++) {
            if (security[i - 1] >= security[i]) {
                left[i] = left[i - 1] + 1;
            }
        }
        vector<int> right(n);
        for (int i = n - 2; i >= 0; i--) {
            if (security[i + 1] >= security[i]) {
                right[i] = right[i + 1] + 1;
            }
        }
        vector<int> ans;  // vector 用作 Java 中的 ArrayList
        for (int i = 0; i < n; i++) {
            if (left[i] >= time && right[i] >= time) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    /*
     * 2099. 找到和最大的长度为 K 的子序列
     */
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back(make_pair(i, nums[i]));  // pair(下标, 值)
        }
        sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b) {  // 自定义结构体排序
            return a.second > b.second;
        });

        while (vec.size() > k) {
            vec.pop_back();
        }
        sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first;
        });
        vector<int> ans;
        for (auto &it: vec) ans.push_back(it.second);
        return ans;
    }
};