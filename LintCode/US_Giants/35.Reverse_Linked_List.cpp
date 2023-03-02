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
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head)
    {
        // write your code here
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p0 = head, *p1 = head;
        while (p0->next != NULL)
            p0 = p0->next;
        do
        {
            head = head->next;
            p1->next = p0->next;
            p0->next = p1;
            p1 = head;
        } while (head != p0);
        return p0;
    }
};