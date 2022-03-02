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
     * 2187. 完成旅途的最少时间
     * 给出每个车完成一趟 所需要的时间 数组 time[]，和总共需要跑的趟数 totalTrips
     * 求总共需要多少时间完成
     * e.g.
     * time = [1,2,3], totalTrips = 5
     * -> 3
     *
     * 二分
     */
    bool isCool(vector<int> &time, long long totalTime, int totalTrips) {
        int n = time.size();
        for (int i = 0; i < n; i++) {
            int t = totalTime / time[i];
            totalTrips -= t;
            if (totalTrips <= 0) return true;
        }
        return false;
    }

    long long minimumTime(vector<int> &time, int totalTrips) {
        int n = time.size();
        long long r = LONG_LONG_MAX;  // 取 long long 的最大值
        for (int i = 0; i < n; i++) {
            long long t = (long long) time[i] * (long long) totalTrips;  // 强制转型
            // 两个单位不一样的数运算，遵循升级原则，可升级
            r = min(r, t);
        }
        long long l = 1;
        while (l < r) {
            long long m = (l + r) >> 1;
            if (isCool(time, m, totalTrips)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    /*
     * 2179. 统计数组中好三元组数目
     * 统计数组中好三元组数目
     * 树状数组
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
            update(pos[nums1[i - 1]] + 1);
            int p = pos[nums1[i]];
            int t = query(p);  // p 左边有多少小于 p 的
            ans += static_cast<long long>(t) * (n - i - p + t - 1);
        }

        return ans;
    }

    static int lowBit(int x) {
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
};