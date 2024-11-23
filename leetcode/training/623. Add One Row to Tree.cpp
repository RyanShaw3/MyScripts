#include <iostream>
#include <vector>
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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);
        vector<TreeNode *> q = {root};
        for (int i = 1; i < depth - 1; i++)
        {
            vector<TreeNode *> t;
            for (auto &node : q)
            {
                if (node->left != nullptr)
                    t.emplace_back(node->left);
                if (node->right != nullptr)
                    t.emplace_back(node->right);
            }
            q = t;
        }
        for (auto &node : q)
        {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }
        return root;
    }
};