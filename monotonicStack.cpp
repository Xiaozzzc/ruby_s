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

/*
 * 496. 下一个更大元素 I
 * nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
 * 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
 *
 * e.g.
 * nums1 = [4,1,2], nums2 = [1,3,4,2]
 * -> [-1,3,-1]
 *
 * 单调栈
 */
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> st;  // 单调递减栈
    int n = nums2.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        while (!st.empty()) {
            int u = st.top();
            if (nums2[u] < nums2[i]) {
                st.pop();
                mp[nums2[u]] = nums2[i];
            } else break;
        }
        st.push(i);
    }
    int m = nums1.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        ans[i] = mp[nums1[i]] == 0 ? -1 : mp[nums1[i]];
    }
    return ans;
}