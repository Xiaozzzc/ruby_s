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

class TreeArray {
public:
    /*
     * 2179. 统计数组中好三元组数目
     * 给你两个下标从 0 开始且长度为 n 的整数数组 nums1 和 nums2 ，两者都是 [0, 1, ..., n - 1] 的 排列 。
     * 好三元组 指的是 3 个 互不相同 的值，且它们在数组 nums1 和 nums2 中出现"顺序"保持一致。
     * 请你返回好三元组的 总数目 。
     *
     * e.g.
     * nums1 = [2,0,1,3], nums2 = [0,1,2,3]
     * -> 1
     * 解释：总共有 4 个三元组 (x,y,z) 满足 pos1x < pos1y < pos1z ，分别是 (2,0,1) ，(2,0,3) ，(2,1,3) 和 (0,1,3) 。
     * 这些三元组中，只有 (0,1,3) 满足 pos2x < pos2y < pos2z 。所以只有 1 个好三元组。
     *
     * nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
     * -> 4
     *
     * 等价转换 + 树状数组
     * 树状数组 适用于 需要知道 该数组每一位 左面有多少小于它的，右面有多少大于他的（从左面有多少小于的可以推导），两者一乘
     */
    vector<int> tree;

    long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        // 把 nums1 等价转换为 0, 1, 2 ...
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i;
        }

        long long ans = 0;
        tree.resize(n + 1);

        // 只需要在 [1, n-1) 范围内枚举 pos1_y 即可
        for (int i = 1; i < n - 1; ++i) {
            update(pos[nums1[i - 1]] + 1);  // 添加的时候，需要 + 1
            int p = pos[nums1[i]];
            int t = query(p);  // p 左边有多少小于 p 的；query 查的是小于等于，不过没关系
            ans += static_cast<long long>(t) * (n - i - p + t - 1);
        }

        return ans;
    }

    int lowBit(int x) {
        return x & (-x);
    }

    // 将 x 记录在数组中
    void update(int x) {
        while (x < tree.size()) {
            ++tree[x];
            x += lowBit(x);
        }
    }

    // 查找 <= x 的项目的个数
    int query(int x) {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowBit(x);
        }
        return ans;
    }
private:
};