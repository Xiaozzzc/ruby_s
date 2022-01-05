#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


class DP {
public:
    /*
     * 377. 组合总和 Ⅳ
     * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target
     * 请你从 nums 中找出并返回总和为 target 的元素组合的个数
     *
     * e.g.
     * nums = [1,2,3], target = 4
     * -> 7
     * 所有可能的组合为：
     * (1, 1, 1, 1)
     * (1, 1, 2)
     * (1, 2, 1)
     * (1, 3)
     * (2, 1, 1)
     * (2, 2)
     * (3, 1)
     * 注，顺序不同的序列被视作不同的组合
     *
     * 并非 完全背包问题，易迷惑
     */
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> f(target + 1);
        f[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int num: nums) {
                if (i >= num && f[i - num] < INT_MAX) {  // 有毒吧
                    f[i] += f[i - num];
                }
            }
        }
        return f[target];
    }
};
