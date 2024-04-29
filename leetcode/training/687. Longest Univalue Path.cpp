#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans;
    int longestUnivaluePath(TreeNode *root)
    {
        ans = 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int left1 = 0, right1 = 0;
        if (root->left && root->val == root->left->val)
            left1 = left + 1;
        if (root->right && root->val == root->right->val)
            right1 = right + 1;
        ans = max(ans, left1 + right1);
        return max(left1, right1);
    }
};