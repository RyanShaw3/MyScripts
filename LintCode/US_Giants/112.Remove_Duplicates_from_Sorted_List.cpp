/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
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

class Solution
{
public:
    /**
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode *deleteDuplicates(ListNode *head)
    {
        // write your code here
        ListNode *p1 = head, *p2 = head;
        while (p1 != NULL)
        {
            int num = p1->val;
            while (p2 != NULL && p2->val == num)
                p2 = p2->next;
            p1->next = p2;
            p1 = p1->next;
        }
        return head;
    }
};