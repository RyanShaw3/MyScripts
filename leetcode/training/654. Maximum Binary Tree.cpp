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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return construct(nums, 0, nums.size() - 1);
    }
    TreeNode *construct(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int center = left;
        for (int i = left + 1; i <= right; i++)
            if (nums[i] > nums[center])
                center = i;
        TreeNode *l = construct(nums, left, center - 1);
        TreeNode *r = construct(nums, center + 1, right);
        TreeNode *father = new TreeNode(nums[center], l, r);
        return father;
    }
};