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
#include "learning.cpp"
#include "binarySearch.cpp"
#include "linkedLst.cpp"

using namespace std;

int main() {
    tuple<int, char, double> mytuple(10, 'a', 3.14);
    pair<int, string> p(0, "sss");
    pair<int, string> p1 = make_pair(9, "9");
    std::cout << "mytuple has ";
    std::cout << std::tuple_size<decltype(mytuple)>::value;
    std::cout << " elements." << '\n';

    Solution solution;
    Learning learning;
    BinarySearch binarySearch;
    vector<int> dist = {1,1,0,0,1};
    vector<int> speed = {18, 54, 2, 53, 87, 31, 71, 4, 29, 25};
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {3, 1, 2},
                                  {2, 3, 1}};
    vector<string> start = {"ant", "act", "tack"};
    vector<string> target = {"tack", "act", "acti"};

    ListNode* node3 = new ListNode(3, nullptr);
    ListNode* node2 = new ListNode(6, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* node0 = new ListNode(5, node1);

    // learning.vecTest();
    // solution.minSwaps(dist);

    return 0;
}
