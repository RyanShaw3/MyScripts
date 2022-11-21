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
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // write your code here
        if (n <= 0)
            return head;
        ListNode *p0 = new ListNode(0);
        p0->next = head;
        ListNode *p1 = p0, *p2 = head;
        while (n--)
            p2 = p2->next;
        while (1)
        {
            if (p2 == NULL)
            {
                ListNode *temp = p1->next;
                p1->next = temp->next;
                delete temp;
                break;
            }
            p2 = p2->next;
            p1 = p1->next;
        }
        return p0->next;
    }
};