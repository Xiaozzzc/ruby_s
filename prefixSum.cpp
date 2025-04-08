#include "dfs.cpp"
#include "linkedLst.cpp"
#include "utils.cpp"
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

class prefixSum {
public:
    // 2874. Maximum Value of an Ordered Triplet II
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n, 0); // L[i] is max num index < i
        vector<int> R(n, 0);
        for (int i = 1; i < n; i++) {
            L[i] = max(L[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            R[i] = max(R[i + 1], nums[i + 1]);
        }
        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            ans = max(ans, (long long) (L[j] - nums[j]) * R[j]);
        }
        return ans;
    }

    // 2873. Maximum Value of an Ordered Triplet I
    // brute force approach
    long long maximumTripletValue1(vector<int>& nums) {
        int i = 0, j = 1, k = 2;
        int n = nums.size();
        long long ans = 0;
        while (i < j) {
            long long ni = nums[i];
            j = i + 1;
            while (j < k) {
                long long nj = nums[j];
                k = j + 1;
                while (k < n) {
                    long long nk = nums[k];
                    ans = max(ans, (ni - nj) * nk);
                    k++;
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};