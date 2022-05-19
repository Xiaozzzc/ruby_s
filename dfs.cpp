#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class DFS {
public:

    /*
     * 2267. 检查是否有合法括号字符串路径
     *
     * 给出一个由 "(" ")" 组成的矩阵，现在要从矩阵的左上角到右下角，每一步可往下或往右
     * 求经过路径上的所有符号，是否组成一个合法的括号序列
     *
     * 记忆化搜索
     */
    bool hasValidPath(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        bool state = false;
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(100)));  // 记忆化矩阵

        // 定义内部函数
        // function<void(int, int, int)> —— 定义函数，输入为 (int, int, int)
        // [&dfs, &grid, &state, &visited, mp, n] —— 引用外部的元素
        function<void(int, int, int)> dfs = [&dfs, &grid, &state, &visited, m, n](int i, int j, int cnt) {
            if (state) {
                return;
            }
            if (visited[i][j][cnt] != 0) {
                return;
            }
            visited[i][j][cnt] = 1;
            if (grid[i][j] == '(') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt < 0 || cnt > (m - 1 - i) + (n - 1 - j)) {  // 此处 cnt > (mp - 1 - i) + (n - 1 - j) 条件不能少，否则超空间复杂度
                return;
            }
            if (i + 1 == m && j + 1 == n) {
                state = true;
                return;
            }
            if (i + 1 < m) {
                dfs(i + 1, j, cnt);
            }
            if (j + 1 < n) {
                dfs(i, j + 1, cnt);
            }
        };

        dfs(0, 0, 0);
        return state;
    }

    /*
     * 2246. 相邻字符不同的最长路径
     *
     * n 个节点编号 0 - n-1，parent 长为 n 记录每个节点的父节点，s 为每个节点的值。
     * 求最长"不"同值路径，带返回，并非从上到下。
     *
     * p.s.
     * a -> b -> c 路径长为 3
     */
    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            int p = parent[i];
            tree[p].push_back(i);
        }
        int ret = 1;
        int st = 0;
        dfs(st, s, tree, ret);
        return ret;
    }

    // 此处，string 记得使用地址 '&'，否则会严重影响速度导致超时
    // 尽量用 '&' ，能提速不少
    int dfs(int &cur, string &s, vector<vector<int>> &tree, int &ret) {  // 此处，string 记得使用地址 '&'，否则会严重影响速度导致超时
        int m0 = 0, m1 = 0;
        for (int u: tree[cur]) {  // 此处，如果把这个提出来 vector<int> children = tree[cur] 会影响速度
            int t = dfs(u, s, tree, ret);
            if (s[u] == s[cur]) continue;
            if (t > m0) {
                m1 = m0;
                m0 = t;
            } else if (t > m1) {
                m1 = t;
            }
        }
        ret = max(ret, m0 + m1 + 1);
        return m0 + 1;
    }

    /*
     * 687. 最长同值路径
     *
     * 二叉树，求最长同值路径，带返回，并非从上到下。
     *
     * p.s.
     * a -> b -> c 路径长为 2
     */
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);
        return ret - 1;
    }

    int ret = 0;

    int dfs(TreeNode* tn) {
        if (tn == nullptr) return 0;
        int l = dfs(tn->left);
        int r = dfs(tn->right);
        l = tn->left != nullptr && tn->val == tn->left->val ? l : 0;
        r = tn->right != nullptr && tn->val == tn->right->val ? r : 0;
        ret = max(ret, l + r + 1);
        return max(l, r) + 1;
    }
};