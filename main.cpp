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
#include "learning.cpp"
#include "binarySearch.cpp"
#include "linkedLst.cpp"

using namespace std;

class Solution {
public:

    /*
     * 2136. 全部开花的最早一天
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

    int makeInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans |= 1 << (s[i] - 'a');
        }
        return ans;
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int m = startWords.size();
        int n = targetWords.size();
        // target 长度为 start + 1
        // target 组成为 start + 任意字符
        map<int, vector<int>> startMp;
        for (int i = 0; i < m; i++) {
            string s = startWords[i];
            int sLen = s.size();
            if (startMp.find(sLen) == startMp.end()) {
                vector<int> curVec;
                curVec.push_back(makeInt(s));
                startMp[sLen] = curVec;
                continue;
            }
            startMp[sLen].push_back(makeInt(s));
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s = targetWords[i];
            if (startMp.find(s.size() - 1) == startMp.end()) {
                continue;
            }
            vector<int> curInt = startMp[s.size() - 1];
            int targetInt = makeInt(s);
            for (int j = 0; j < curInt.size(); j++) {
                int startInt = curInt[j];
                if (fit(startInt, targetInt)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }

    // 自己定义了比较函数，自己遍历数组来挨个比较，不如直接用 set 来的直接
    // 都是26位
    bool fit(int startInt, int targetInt) {  // 不用自己定义比较函数
        // 只有一位diff，且那位 startVec 是 0，targetVec是 1
        if ((startInt & targetInt) == startInt) {
            return true;
        }
        return false;
    }


    /*
     * 5977. 最少交换次数来组合所有的 1 II
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
        int k = 0;  // k 是 nums 中的 1 的个数，大小为 k 的滑动窗口
        for (auto num: nums) {
            if (num == 1) k++;
        }
        if (k == 0) return 0;
        vector<int> ring = nums;  // 拼接数组
        ring.insert(ring.end(), nums.begin(), nums.end());  // vector insert 的用法
        int n = ring.size();
        int cnt = 0;
        int ans = INT_MAX;  // 最大的 int
        for (int i = 0; i < n; ++i) {
            if (ring[i] == 1) {
                cnt++;  // cnt 为滑动窗口中 1 的个数
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

    int minSwaps1(vector<int>& nums) {
        int cnt = accumulate(nums.begin(), nums.end(), 0);  // 统计 数组中 0 的个数
        if (cnt == nums.size() || cnt == 0 || cnt == 1) return 0;

        int j = 0;
        int window = 0;  // 窗口中 1 的个数
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (true) {
                int x = (i > j) ? nums.size() + j : j;
                if (x >= i + cnt) break;
                window += nums[j];
                j = (j + 1 == nums.size()) ? 0 : j + 1;
            }
            ans = min(ans, cnt - window);
            window -= nums[i];
        }
        return ans;
    }

    // 2076. 处理含限制条件的好友请求
};

int main() {

    tuple<int, char, double> mytuple(10, 'a', 3.14);

    std::cout << "mytuple has ";
    std::cout << std::tuple_size<decltype(mytuple)>::value;
    std::cout << " elements." << '\n';

    Solution solution;
    Learning learning;
    BinarySearch binarySearch;
    vector<int> dist = {3, 2, 1};
    vector<int> speed = {0, 3, 3};
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {3, 1, 2},
                                  {2, 3, 1}};
    vector<string> start = {"ant", "act", "tack"};
    vector<string> target = {"tack", "act", "acti"};
    ListNode* node3 = new ListNode(3, nullptr);
    ListNode* node2 = new ListNode(6, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* node0 = new ListNode(5, node1);

    learning.vecTest();

    return 0;
}
