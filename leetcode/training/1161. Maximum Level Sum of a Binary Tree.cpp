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
    int maxLevelSum(TreeNode *root)
    {
        int ans = 1, maxSum = root->val;
        vector<TreeNode *> q1 = {root};
        for (int i = 1; !q1.empty(); i++)
        {
            int sum = 0;
            vector<TreeNode *> q2;
            for (auto node : q1)
            {
                sum += node->val;
                if (node->left)
                    q2.emplace_back(node->left);
                if (node->right)
                    q2.emplace_back(node->right);
            }
            if (sum > maxSum)
            {
                maxSum = sum;
                ans = i;
            }
            q1 = q2;
        }
        return ans;
    }
};