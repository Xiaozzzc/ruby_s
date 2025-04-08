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
#include "dp.cpp"
#include "learning/learning.cpp"
#include "learning/memcpyTest.cpp"
#include "learning/nameSpace.cpp"
#include "learning/operatorTest.cpp"
#include "learning/pointerTest.cpp"
#include "learning/stdTest.cpp"
#include "learning/templateTest.cpp"

using namespace std;


int main() {
    std::mutex raftLock_;
    std::lock_guard<std::mutex> g(raftLock_);

    Learning learning;
    learning.vecTest();
    learning.mapTest();
    learning.setTest();
    learning.stringTest();

    Solution solution;

    ListNode* node3 = new ListNode(3, nullptr);
    ListNode* node2 = new ListNode(6, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* node0 = new ListNode(5, node1);

    /*
     * 1
     * |\
     * 3 4
     * | |\
     * 2 6 5
     *   |  \
     *   8   7
     */
    TreeNode* tn7 = new TreeNode(7);
    TreeNode* tn5 = new TreeNode(5, NULL, tn7);
    TreeNode* tn8 = new TreeNode(8);
    TreeNode* tn6 = new TreeNode(6, tn8, NULL);
    TreeNode* tn2 = new TreeNode(2);
    TreeNode* tn4 = new TreeNode(4, tn6, tn5);
    TreeNode* tn3 = new TreeNode(3, tn2, NULL);
    TreeNode* tn1 = new TreeNode(1, tn3, tn4);

    vector<vector<int>> matrix = {
        {3,2},
        {4,3},
        {4,4},
        {2,5},
    };

    vector<vector<char>> charMatrix = {
        {'#','.','*','.'},
        {'#','#','*','.'},
    };


    vector<string> start = {"ant", "act", "tack"};
    vector<string> target = {"tack", "act", "acti"};
    vector<int> vec = {1,2,3};
    string s = "00000000";


    size_t st = 10;
    cout << st << endl;

    string s1 = "siyolsdcjthwsiplccjbuceoxmpjgrauocx";
    string s2 = "siyolsdcjthwsiplccpbuceoxmjjgrauocx";

    // solution.largestDivisibleSubset(vec);
    // solution.lengthOfLIS(vec);
    // solution.subsetXORSum(vec);
    // solution.lcaDeepestLeaves(tn0);
    // solution.longestPalindrome("abcde", "ecdba");
    // solution.longestPalindrome1("babad");
    // solution.maximumScore(vec, 6);
    // solution.minimizedMaximum(7, vec);

    // solution.maximumWhiteTiles(u, 2);



    return 0;
}
