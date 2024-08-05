#include <iostream>
#include <vector>
#include <string>
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
    vector<vector<string>> printTree(TreeNode *root)
    {
        int h = getDepth(root);
        int m = h + 1, n = (1 << (h + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        dfs(res, root, h, 0, (n - 1) / 2);
        return res;
    }
    int getDepth(TreeNode *root)
    {
        int h = 0;
        if (root->left)
            h = max(h, getDepth(root->left) + 1);
        if (root->right)
            h = max(h, getDepth(root->right) + 1);
        return h;
    }
    void dfs(vector<vector<string>> &res, TreeNode *root, const int &h, int r, int c)
    {
        res[r][c] = to_string(root->val);
        if (root->left)
            dfs(res, root->left, h, r + 1, c - (1 << (h - r - 1)));
        if (root->right)
            dfs(res, root->right, h, r + 1, c + (1 << (h - r - 1)));
        return;
    }
};