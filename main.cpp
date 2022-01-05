#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 2071. 你可以安排的最多任务数目
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end(), [](int a, int b) { return b > a; });  // 从大到小
        sort(workers.begin(), workers.end());  // 从小到大排序
        int n = min(tasks.size(), workers.size());
        int l = 0, r = n;  // 考虑最好情况
        while (l < r) {
            int m = (l + r) >> 1;
            if (canDo(tasks, workers, pills, strength, m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    bool canDo(vector<int> &tasks, vector<int> &workers, int pills, int strength, int num) {
        // 找出最好的num个人，做最简单的num个事情
        // 给最弱的几个吃药丸，然后重新排序
        vector<int> curWorkers(num);
        for (int i = 0; i < num; i++) {
            curWorkers[i] = workers[i];
        }
        int t = num - 1;
        while (pills > 0) {
            curWorkers[t] += strength;
            pills--;
        }
        sort(curWorkers.begin(), curWorkers.end(), [](int a, int b) { return b > a; });
        for (int i = 0; i < num; i++) {
            int a = curWorkers[i];
            int b = tasks[i];
            if (curWorkers[i] < tasks[i]) return false;
        }
        return true;
    }

    // 2074. 反转偶数长度组的节点
    // 2076. 处理含限制条件的好友请求
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
