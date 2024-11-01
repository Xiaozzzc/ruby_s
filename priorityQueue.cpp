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


class PriorityQueue {
public:

    // 2233. Maximum Product After K Increments
    int maximumProduct(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  // 最小堆 升序的优先队列

        for (auto i: nums) {
            pq.push(i);
        }
        for (int i = 0; i < k; i++) {
            int tmp = pq.top();
            pq.pop();
            tmp++;
            pq.push(tmp);
        }
        long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % 100000007;
            pq.pop();
        }
        return ans;
    }
};