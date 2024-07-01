#include <iostream>
#include <unordered_map>
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
    unordered_map<int, unsigned long long> ump;
    unsigned long long ans;
    int widthOfBinaryTree(TreeNode *root)
    {
        dfs(root, 0, 1);
        return ans;
    }
    void dfs(TreeNode *root, int depth, unsigned long long idx)
    {
        if (root == nullptr)
            return;
        if (!ump.count(depth))
            ump[depth] = idx;
        ans = max(ans, idx - ump[depth] + 1);
        dfs(root->left, depth + 1, idx * 2 - 1);
        dfs(root->right, depth + 1, idx * 2);
    }
};