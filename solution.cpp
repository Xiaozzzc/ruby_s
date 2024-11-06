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
#include "dfs.cpp"
#include "utils.cpp"
#include "linkedLst.cpp"

using namespace std;

class Solution {
public:
    template<typename T>
    void swap(T &a, T &b) {
        T c = a;
        a = b;
        b = c;
    }
};
