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
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // write your code here
        ListNode *p0 = new ListNode(-1);
        p0->next = l1;
        ListNode *p1 = p0, *p2 = l2;
        while (p2 != NULL)
        {
            int num = p2->val;
            while (p1->next != NULL && p1->next->val < num)
                p1 = p1->next;
            // 合并到l1中
            ListNode *temp = p2;
            p2 = p2->next;
            temp->next = p1->next;
            p1->next = temp;
        }
        return p0->next;
    }
};