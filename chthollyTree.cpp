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

// 珂丽朵树（合并树）

/*
 * 2276. 统计区间中的整数数目
 * 实现一个类
 * add(int left, int right) —— 添加区间 [left, right]
 * count() —— 返回区间内的整数数目
 *
 * ex.
 * CountIntervals countIntervals = new CountIntervals(); // 用一个区间空集初始化对象
 * countIntervals.add(2, 3);  // 将 [2, 3] 添加到区间集合中
 * countIntervals.add(7, 10); // 将 [7, 10] 添加到区间集合中
 * countIntervals.count();    // 返回 6
 *                            // 整数 2 和 3 出现在区间 [2, 3] 中
 *                            // 整数 7、8、9、10 出现在区间 [7, 10] 中
 * countIntervals.add(5, 8);  // 将 [5, 8] 添加到区间集合中
 * countIntervals.count();    // 返回 8
 *
 * 珂朵莉树 —— 求区间并集
 */
class CountIntervals {
    int ans = 0;
    set<pair<int, int>> st;  // set 内部是有序的

public:
    CountIntervals() {
    }

    void add(int left, int right) {
        // pair<> 也可以 lower_bound
        auto it = st.lower_bound(pair<int, int>(left - 1, -2e9));  // set 内部是有序的，可以使用 lower_bound
        while (it != st.end()) {
            if (it->second > right + 1) break;
            left = min(left, it->second);
            right = max(right, it->first);
            ans -= it->first - it->second + 1;
            st.erase(it++);
        }
        ans += right - left + 1;
        st.insert(pair<int, int>(right, left));  // 注意是 (R, L)
    }

    int count() {
        return ans;
    }
};