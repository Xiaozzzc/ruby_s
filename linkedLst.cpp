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

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LinkedLst {
public:
    /*
     * 2074. 反转偶数长度组的节点
     * 将链表从头开始，以 1，2，3，4 ... 个节点来分组，反转偶数长度组的节点
     */
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
};