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
     * @return: nothing
     */
    ListNode *getMiddleNode(ListNode *left, ListNode *right)
    {
        ListNode *fast = left;
        ListNode *slow = left;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverseList(ListNode *left, ListNode *right)
    {
        ListNode *head = left;
        ListNode *prevNode = NULL;
        while (head != right)
        {
            ListNode *next = head->next;
            head->next = prevNode;
            prevNode = head;
            head = next;
        }
        return prevNode;
    }
    void *mergeLists(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1;
        ListNode *temp2;
        while (l1 != NULL && l2 != NULL)
        {
            temp1 = l1->next;
            temp2 = l2->next;
            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2;
        }
    }
    void reorderList(ListNode *head)
    {
        // write your code here
        if (head == NULL || head->next == NULL)
            return;
        ListNode *mid = this->getMiddleNode(head, NULL);
        ListNode *head1 = head;
        ListNode *head2 = this->reverseList(mid->next, NULL);
        mid->next = NULL;
        this->mergeLists(head1, head2);
        return;
    }
};