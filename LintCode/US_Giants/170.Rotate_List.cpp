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
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k)
    {
        // write your code here
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *p1 = head;
        int len = 1;
        while (p1->next != NULL)
        {
            len++;
            p1 = p1->next;
        }
        int offset = len - k % len; // 可能旋转超过一圈
        if (offset == len)
            return head;
        p1->next = head;
        while (offset--)
            p1 = p1->next;
        ListNode *h = p1->next;
        p1->next = NULL;
        return h;
    }
};