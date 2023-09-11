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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode *partition(ListNode *head, int x)
    {
        // write your code here
        ListNode *p = new ListNode(-1);
        p->next = head;
        ListNode *p0 = p;
        while (p0->next != NULL && p0->next->val < x)
            p0 = p0->next;
        ListNode *p1 = p0;
        while (p1->next != NULL)
        {
            if (p1->next->val < x)
            {
                ListNode *temp = p1->next;
                p1->next = temp->next;
                temp->next = p0->next;
                p0->next = temp;
                p0 = p0->next;
            }
            else
                p1 = p1->next;
        }
        return p->next;
    }
};