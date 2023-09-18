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
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode *sortList(ListNode *head)
    {
        // write your code here
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return this->mergeTwoLists(sortList(head), sortList(fast));
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *p0 = new ListNode(-1);
        p0->next = l1;
        ListNode *p1 = p0, *p2 = l2;
        while (p2 != NULL)
        {
            int num = p2->val;
            while (p1->next != NULL && p1->next->val < num)
                p1 = p1->next;
            ListNode *temp = p2;
            p2 = p2->next;
            temp->next = p1->next;
            p1->next = temp;
        }
        return p0->next;
    }
};