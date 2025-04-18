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
    // quick power
    long long quickPow(long long a, long long b, int mod) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1) {
                ans = ans * a % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans % MOD;
    }

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

    const int MOD = 1e9 + 7;
    // 1922. Count Good Numbers
    // a number is a "good number string" when it's even index digits are even(0,2,4,6,8) and odd index digits are prime(2,3,5,7)
    // e.g.
    // "2582" -> good
    // "3245" -> not good
    // given a number n return the total number of "good number string" with the length of n
    // quick power
    int countGoodNumbers(long long n) {
        long long b = n / 2;
        int ans = 1;
        if (n % 2 == 1) {
            ans = 5;
        }
        ans = (ans * quickPow(5, b, MOD)) % MOD;
        ans = (ans * quickPow(4, b, MOD)) % MOD;
        // ans *= quickPow(5, b, mod) % mod;
        // ans *= quickPow(4, b, mod) % mod;
        return ans % MOD;
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
