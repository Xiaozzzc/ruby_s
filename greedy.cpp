#include "dfs.cpp"
#include "linkedLst.cpp"
// #include "utils.cpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class greedy {
public:
    // 3396. Minimum Number of Operations to Make Elements in Array Distinct
    int minimumOperations(vector<int>& nums) {
        vector<int> mpp(101);
        for (int i = nums.size() - 1; i >= 0; --i)
            if (++mpp[nums[i]] > 1)
                return (i + 3) / 3;
        return 0;
    }
};
