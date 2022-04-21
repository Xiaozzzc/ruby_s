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
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root);
        return ret - 1;
    }

    int ret = 0;

    int dfs(TreeNode* tn) {
        if (tn == nullptr) return 0;
        int l = dfs(tn->left);
        int r = dfs(tn->right);
        if (tn->left != nullptr && tn->val == tn->left->val) {
        } else l = 0;
        if (tn->right != nullptr && tn->val == tn->right->val) {
        } else r = 0;
        ret = max(ret, l + r + 1);
        return max(l, r) + 1;
    }
};