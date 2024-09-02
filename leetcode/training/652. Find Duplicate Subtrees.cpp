#include <iostream>
#include <vector>
#include <string>
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
    vector<TreeNode *> ans;
    unordered_map<string, int> ump;
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
    string dfs(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        string s = to_string(root->val) + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
        ump[s]++;
        if (ump[s] == 2)
            ans.emplace_back(root);
        return s;
    }
};