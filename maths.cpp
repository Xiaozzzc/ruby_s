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

class Maths {
public:
    // get primes of a given number
    // n = 18 -> [2, 3, 3]
    vector<int> getPrimes(int n) {
        vector<int> primes;
        while (n % 2 == 0) {
            n /= 2;
            primes.push_back(2);
        }
        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                n /= i;
                primes.push_back(i);
            }
        }
        return primes;
    }

    // greatest common divider
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int gcd1(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Median
    // 2033. Minimum Operations to Make a Uni-value Grid
    // In one operation, you can add x to or subtract x from any element in the 2D grid
    // Return the minimum number of operations to make the grid uni-value, return -1 if not possible
    // grid = [[2,4],[6,8]], x = 2
    // -> 4
    // add 2 to 2, subtract 2 from 6, subtract 2 from 8 twice, reach all 4
    // grid = [[1,5],[2,3]], x = 1 -> 5
    // grid = [[1,2],[3,4]], x = 2 -> -1
    int minOperations(vector<vector<int>>& grid, int x) {
        int base = grid[0][0];
        vector<int> vec;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int cur = grid[i][j];
                if ((cur - base) % x != 0) {
                    return -1;
                }
                vec.push_back(cur);
            }
        }
        sort(vec.begin(), vec.end());
        int goal = vec[vec.size() / 2];
        int ans = 0;
        for (int u : vec) {
            ans += abs(u - goal) / x;
        }
        return ans;
    }
};
