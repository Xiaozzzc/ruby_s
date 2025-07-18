#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


class BinarySearch {
public:
    // lower_bound return the first vec >= u
    int lower_bound(vector<int> vec, int u) {
        int l = 0, r = vec.size();  // * r = vec.size()
        while (l < r) {  // * l < r
            int mid = l + r >> 1;
            if (vec[mid] >= u) {  // * vec[mid] >= u, if descending sequence vec <= u
                r = mid;
            } else {
                l = mid + 1; // * l = mid + 1, l = mid might go into an infinite loop
            }
        }
        return l;
    }

    // upper_bound return the first num > t

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
    bool isCool(vector<int>& time, long long totalTime, int totalTrips) {
        int n = time.size();
        for (int i = 0; i < n; i++) {
            int t = totalTime / time[i];
            totalTrips -= t;
            if (totalTrips <= 0) return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long r = LONG_LONG_MAX; // 取 long long 的最大值
        for (int i = 0; i < n; i++) {
            long long t = (long long) time[i] * (long long) totalTrips; // 强制转型
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

    // 2071. 你可以安排的最多任务数目
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end()); // 事情难度，从小到大
        sort(workers.begin(), workers.end(), [](int a, int b) { return a > b; }); // 工人能力从大到小
        int n = min(tasks.size(), workers.size());
        int l = 0, r = n + 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (canDo(tasks, workers, pills, strength, m)) {
                l = m + 1; // 注意，l最终是"上层"的第一个
            } else {
                r = m;
            }
        }
        return l - 1;
    }


    bool canDo(vector<int>& tasks, vector<int>& workers, int pills, int strength, int num) {
        // 找出最好的num个人，做最简单的num个事情
        // 给最弱的几个吃药丸，然后重新排序；如果这样，结果会是错的，因为 "为了完成所有任务，药丸不一定给最弱的人吃"
        vector<int> curWorkers(num);
        for (int i = 0; i < num; i++) {
            curWorkers[i] = workers[i]; // 力量最大的num个人
        }
        for (int i = num - 1; i >= 0; i--) {
            int curTask = tasks[i];
            bool found = false;
            for (int j = 0; j < num; j++) {
                if (curWorkers[j] >= curTask) {
                    curWorkers[j] = -1;
                    found = true;
                    break;
                }
            }
            if (found) continue;
            if (pills == 0) return false;
            for (int j = num - 1; j >= 0; j--) {
                int curW = curWorkers[j];
                if (curW < 0) continue;
                if (pills > 0 && curW + strength >= curTask) {
                    curWorkers[j] = -1;
                    pills--;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

    // 2064. minimized-maximum-of-products-distributed-to-any-store
    int minimizedMaximum(int stores, vector<int>& qty) {
        int low = 1, high = *max_element(qty.begin(), qty.end());
        while (low < high) {
            int mid = (low + high) / 2;
            int needed = 0;
            for (int q : qty) {
                needed += (q + mid - 1) / mid;
            }
            if (needed <= stores) {
                high = mid;
            } else
                low = mid + 1;
        }
        return low;
    }
};
