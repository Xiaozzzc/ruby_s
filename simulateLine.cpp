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
#include "utils.cpp"

using namespace std;


/*
 * 6076. 表示一个折线图的最少线段数
 * 给出一个数组 stockPrices，其中每一个元素是一个点，所有点构成一个折线图
 * 求构成这个折线图，需要多少条"直线"拼接起来？
 *
 * 三点一线，直线上最多的点数
 * 这种题需要用 gcd 最大公约数 + string 来记录斜率，否则 double 记录斜率，精度还是不够
 * 或者使用 long double ......
*/
int minimumLines(vector<vector<int>> &stockPrices) {
    int n = stockPrices.size();
    if (n < 2) return 0;
    sort(stockPrices.begin(), stockPrices.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];  // a 小于 b，从小到大
    });
    int ans = 1;
    vector<int> base(2);
    base[0] = stockPrices[1][0];
    base[1] = stockPrices[1][1];
    int a = base[1] - stockPrices[0][0];
    int b = base[0] - stockPrices[0][1];
    int k = gcd(a, b);
    string d0 = to_string(a / k) + "_" + to_string(b / k);
    for (int i = 2; i < n; i++) {
        int a1 = stockPrices[i][1] - base[1];
        int b1 = stockPrices[i][0] - base[0];
        int k1 = gcd(a, b);
        string d1 = to_string(a1 / k1) + "_" + to_string(b1 / k1);
        base[0] = stockPrices[i][0];
        base[1] = stockPrices[i][1];
        if (d1 != d0) {
            d0 = d1;
            ans++;
        }
    }
    return ans;
}