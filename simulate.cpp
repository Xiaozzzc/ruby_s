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


class Simulate {
public:

    /*
     * 5987. 删除元素后和的最小差值
     * 给出数组 nums 共有 3n 个元素，现删掉数组中的 n 个元素（元素顺序不变）
     * 使剩下 2n 个元素 "前 n 个之和 - 后 n 个之和" 最小，求该最小值
     *
     * e.g.
     * nums = [7,9,5,8,1,3]
     * -> 1
     * 删除 9, 1 剩余 7, 5, 8, 3 此时 (7 + 5) - (8 + 3) 最小
     *
     * 与动态规划类似 —— 枚举分割点 + 堆
     * 问题等价于：枚举数组的分割点，将数组分成两半，在左侧取最小的 n/3 个元素，在右侧取最大的 n/3 个元素，然后计算左侧的和与右侧的和，取它们的差的最小值
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
     * 5977. 最少交换次数来组合所有的 1 II
     * 给出一个由 0, 1 组合而成的环形数组，每次可以交换 0 和 1 位置，最终使得 0, 1 聚在一起，求最少交换次数
     *
     * [0,1,0,1,1,0,0] -> 1
     * [0,1,1,1,0,0,1,1,0] -> 2
     * [1,0,1,1,1,0,0,1,1,0,1] -> 2
     * 1,1,0,1,1,0,1,1,1,0,0 -> 1,1,2 留一个最大的，求最小的的和
     *
     * [0,1,0,0,1,0,0,0,1] -> 1,2,3
     * 最终状态，0需要聚集在一起，1需要聚集在一起，0和1对等
     */
    int minSwaps(vector<int>& nums) {
        int k = 0;
        for (int t: nums) {
            if (t == 1) k++;
        }
        if (k == 0) return 0;
        vector<int> ring = nums;  // 拼接数组
        ring.insert(ring.end(), nums.begin(), nums.end());  // vector insert 的用法
        int n = ring.size();
        int cnt = 0;  // cnt 为滑动窗口中 1 的个数
        int ans = INT_MAX;  // 最大的 int
        for (int i = 0; i < n; i++) {
            if (ring[i] == 1) {
                cnt++;
            }
            if (i >= k - 1) {
                ans = min(ans, k - cnt);
                if (ring[i - k + 1] == 1) {
                    cnt--;
                }
            }
        }
        return ans;
    }

    /*
     * 5983. 同时运行 N 台电脑的最长时间
     */
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end(), [](int a, int b) { return a > b; });
        // 除了电量最多的n个电池，其他电池包里的电池，是可以任意加的
        int num = batteries.size();
        long long extra = 0;
        for (int i = n; i < num; i++) {
            extra += batteries[i];
        }
        int w = 1;
        long long ans = 0;
        for (int i = n - 1; i > 0; i--) {
            int h = batteries[i - 1] - batteries[i];
            int m = w * h;
            if (extra >= m) {
                extra -= m;
            } else {
                ans = batteries[i] + extra / w;
                break;
            }
            w++;
        }
        if (ans == 0) {
            ans = batteries[0] + extra / w;
        }
        return ans;
    }

    /*
     * 5982. 解决智力问题
     */
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans = 0;
        int n = questions.size();
        vector<long long> dp(n);  // 选该问题 时 最大总得分
        vector<long long> gets(n);
        long long get = 0;
        for (int i = 0; i < n; i++) {
            get = max(get, dp[i]);

            vector<int> question = questions[i];
            dp[i] = get + question[0];
            ans = max(ans, dp[i]);

            if (i + question[1] + 1 < n) {
                dp[i + question[1] + 1] = max(dp[i], dp[i + question[1] + 1]);
            }
        }
        return ans;
    }

    /*
     * 5194. 得到目标值的最少行动次数
     */
    int minMoves(int target, int maxDoubles) {
        // 加倍都要用；且都要用在后面，否则毫无意义
        int cnt = 0;
        while (target > 1) {
            if (maxDoubles == 0) {
                return cnt + target - 1;
            }
            if ((target & 1) == 1) {
                target -= 1;
            } else {
                if (maxDoubles > 0) {
                    target >>= 1;
                    maxDoubles--;
                } else {
                    target -= 1;
                }
            }
            cnt++;
        }
        return cnt;
    }

    /*
     * 2136. 全部开花的最早一天
     *
     * 先种 花生长期长的 绝对没错
     */
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);  // 使用iota将结构体数组填满
        sort(id.begin(), id.end(), [&growTime](int a, int b) { return growTime[a] > growTime[b]; });
        int now = 0;
        int ans = 0;
        for (int u: id) {
            now += plantTime[u];
            ans = max(ans, now + growTime[u]);
        }
        return ans;
    }

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