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
#include "solution.cpp"
#include "learning/nameSpace.cpp"
#include "learning/learning.cpp"
#include "binarySearch.cpp"
#include "linkedLst.cpp"

using namespace std;


int main() {
    ruby::luo::luoFunc();

    Solution solution;
    Learning learning;  // 通过直接声明的方式即可创建对象
    learning.vecTest();
    learning.mapTest();
    learning.setTest();
    learning.stringTest();
    learning.stdTest();
    learning.operatorTest();
    learning.constTest();

    ListNode* node3 = new ListNode(3, nullptr);
    ListNode* node2 = new ListNode(6, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* node0 = new ListNode(5, node1);

#define CREATE_FOR_TYPE(TYPE)
    CREATE_FOR_TYPE(UInt8)
    CREATE_FOR_TYPE(UInt16)
#undef CREATE_FOR_TYPE

    vector<vector<int>> u = {{10, 11},
                             {1, 1}};
    vector<vector<int>> vt = {{0, 1},
                              {2, 3}};

//    sort(u.begin(), u.end(), [vt](vector<int> a, vector<int> b) {
//        return vt[a[0]][a[1]] < vt[b[0]][b[1]];
//    });

    vector<vector<int>> matrix = {{23, 17, 15, 3,  20},
                                  {8,  1,  20, 27, 11},
                                  {9,  4,  6,  2,  21},
                                  {40, 9,  1,  10, 6},
                                  {22, 7,  4,  5,  3}};


    vector<int> dist = {-1, 0, 1};
    vector<int> speed = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};

    vector<string> start = {"ant", "act", "tack"};
    vector<string> target = {"tack", "act", "acti"};
    string s = "00000000";

    // solution.maximumWhiteTiles(u, 2);

    return 0;
}
