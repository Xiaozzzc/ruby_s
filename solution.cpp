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

using namespace std;


class Solution {
public:

    /*
     * 5987. 删除元素后和的最小差值
     * 给出 数组 nums 共有 3n 个元素，现删掉数组中的 n 个元素（元素顺序不变）
     * 使剩下 2n 个元素 "前 n 个之和 - 后 n 个之和" 最小，求该最小值
     *
     * e.g.
     * nums = [7,9,5,8,1,3]
     * -> 1
     * 删除 9, 1 剩余 7, 5, 8, 3 此时 (7 + 5) - (8 + 3) 最小
     *
     * 枚举分割点 + 堆
     * 枚举数组的分割点，将数组分成两半，在左侧取最小的 n/3 个元素，在右侧取最大的 n/3 个元素，然后计算左侧的和与右侧的和，取它们的差的最小值
     */
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;
        long long l = 0, r = 0;  // l是左边的和，r是右边的和
        priority_queue<int> left;  // 小顶堆
        priority_queue<int, vector<int>, greater<>> right;  // 大顶堆
        vector<long long> arr(n + 1);  // arr[i] 是分割点为 nums[i + n] 时右侧(包括分割点)最大的和；分割点可为 nums[n] 到 nums[2n - 1]
        for (int i = 0; i < n; ++i) {
            l += nums[i];
            left.push(nums[i]);
            r += nums[i + 2 * n];
            right.push(nums[i + 2 * n]);
        }
        arr[n] = r;
        for (int i = 2 * n - 1; i >= n; --i) {  // 分割点为 i 时右侧(包括分割点)最大的和，存入 arr
            if (nums[i] > right.top()) {
                r += nums[i] - right.top();
                right.pop();
                right.push(nums[i]);
            }
            arr[i - n] = r;
        }
        long long ret = l - arr[0];
        for (int i = n; i < n * 2; ++i) {  // 求分割点为 i 时左侧最小的和
            if (nums[i] < left.top()) {
                l += nums[i] - left.top();
                left.pop();
                left.push(nums[i]);
            }
            ret = min(ret, l - arr[i - n + 1]);  // 左侧已经包括了分割点，所以取右侧时要 + 1
        }
        return ret;
    }

    /*
     * 2147. 分隔长廊的方案数
     * corridor 是一个走廊，由 P(植物) 和 S(座位) 组成，最初状态左右各一个屏风
     * 现在要放置若干个屏风，使每两个屏风之间恰好有两个座位，求有多少种不同的放置屏风的方法
     */
    int numberOfWays(string corridor) {
        vector<int> u{1, 2, 3};

        return 0;
    }

};
