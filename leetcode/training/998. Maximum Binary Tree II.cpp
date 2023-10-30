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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (val > root->val)
            return new TreeNode(val, root, nullptr);
        TreeNode *father = nullptr, *child = root;
        while (child)
        {
            if (val > child->val)
            {
                TreeNode *node = new TreeNode(val, child, nullptr);
                father->right = node;
                return root;
            }
            father = child;
            child = father->right;
        }
        father->right = new TreeNode(val);
        return root;
    }
};