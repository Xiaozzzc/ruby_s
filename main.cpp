#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <tuple>
#include "binarySearch.cpp"
#include "linkedLst.cpp"

using namespace std;


class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        int n = vec.size();
        int curLen = 1;
        for (int i = 0; i < n;) {
            int nextLen = 0;
            while (nextLen < curLen && i + nextLen < n) {
                nextLen++;
            }
            if (!(nextLen & 1)) {
                reverse(&vec, i, i + nextLen);  // 反转[i, i + nextLen)
            }
            i += curLen;
            curLen++;
        }
        ListNode* ans = new ListNode(vec[0], nullptr);
        ListNode* curNode = ans;
        for (int i = 1; i < n; i++) {
            curNode->next = new ListNode(vec[i], nullptr);
            curNode = curNode->next;
        }
        return ans;
    }

    // [l, r)
    void reverse(vector<int>* vec, int l, int r) {
        // 反转 l, r
        std::reverse(vec->begin() + l, vec->begin() + r);
    }

    // 2074. 反转偶数长度组的节点
    // 原地反转版本
    ListNode* reverseEvenLengthGroups0(ListNode* head) {
        int i = 0;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            ++i;
            ListNode* it = cur;
            int len = 0;
            for (; len < i && it; ++len) {
                it = it->next;
            }

            if (len & 1) {  // 奇数组，不用反转
                for (int j = 1; j <= len; ++j) {
                    tie(pre, cur) = tuple<ListNode*, ListNode*>{cur, cur->next};
                }
            } else {
                for (int j = 1; j < len; ++j) {
                    // 绝了
                    // pre.next, cur.next.next, cur.next = cur.next, pre.next, cur.next.next
                    tie(pre->next, cur->next, cur->next->next) =
                            tuple<ListNode*, ListNode*, ListNode*>{cur->next, cur->next->next, pre->next};
                }
                tie(pre, cur) = tuple<ListNode*, ListNode*>{cur, cur->next};
            }
        }
        return head;
    }
    // 2076. 处理含限制条件的好友请求
};

int main() {

    tuple<int, char, double> mytuple(10, 'a', 3.14);

    std::cout << "mytuple has ";
    std::cout << std::tuple_size<decltype(mytuple)>::value;
    std::cout << " elements." << '\n';

    Solution solution;
    BinarySearch binarySearch;
    vector<int> dist = {3, 2, 1};
    vector<int> speed = {0, 3, 3};
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {1, 2, 3},
                                  {1, 2, 3}};
    ListNode* node3 = new ListNode(3, nullptr);
    ListNode* node2 = new ListNode(6, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* node0 = new ListNode(5, node1);

    solution.reverseEvenLengthGroups(node0);
    return 0;
}
