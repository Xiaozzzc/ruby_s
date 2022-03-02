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
#include "solution.cpp"
#include "learning/nameSpace.cpp"
#include "learning/learning.cpp"
#include "binarySearch.cpp"
#include "linkedLst.cpp"

using namespace std;


int main() {
    ruby::luo::luoFunc();
    tuple<int, char, double> mytuple(10, 'a', 3.14);
    pair<int, string> p(0, "sss");
    pair<int, string> p1 = make_pair(9, "9");
    std::cout << "mytuple has ";
    std::cout << std::tuple_size<decltype(mytuple)>::value;
    std::cout << " elements." << '\n';

    Solution solution;
    Learning learning;  // 通过直接声明的方式即可创建对象
    learning.vecTest();
    BinarySearch binarySearch;

    ListNode* node3 = new ListNode(3, nullptr);
    ListNode* node2 = new ListNode(6, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* node0 = new ListNode(5, node1);

#define CREATE_FOR_TYPE(TYPE)
    CREATE_FOR_TYPE(UInt8)
    CREATE_FOR_TYPE(UInt16)
#undef CREATE_FOR_TYPE

    vector<vector<int>> u = {{0, 1},
                             {0, 0}};
    vector<vector<int>> vt = {{0, 1},
                              {2, 3}};

    sort(u.begin(), u.end(), [vt](vector<int> a, vector<int> b) {
        return vt[a[0]][a[1]] < vt[b[0]][b[1]];
    });


    vector<int> dist = {88690,69213};
    vector<int> speed = {1, 1};
    vector<vector<int>> matrix = {{1, 0, 1},
                                  {3, 5, 2},
                                  {1, 0, 1}};
    vector<string> start = {"ant", "act", "tack"};
    vector<string> target = {"tack", "act", "acti"};
    solution.minimumTime(dist, 90165);
    return 0;
}
