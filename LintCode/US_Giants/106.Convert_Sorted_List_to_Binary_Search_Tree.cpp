/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution
{
public:
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    ListNode *getMiddleNode(ListNode *left, ListNode *right)
    {
        ListNode *fast = left;
        ListNode *slow = left;
        while (fast != right && fast->next != right)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    TreeNode *buildBST(ListNode *left, ListNode *right)
    {
        if (left == right)
            return NULL;
        ListNode *mid = this->getMiddleNode(left, right);
        TreeNode *father = new TreeNode(mid->val);
        father->left = this->buildBST(left, mid);
        father->right = this->buildBST(mid->next, right);
        return father;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        // write your code here
        return this->buildBST(head, NULL);
    }
};