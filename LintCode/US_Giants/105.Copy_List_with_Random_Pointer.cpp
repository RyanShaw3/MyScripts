/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        // write your code here
        if (head == NULL)
            return head;
        for (RandomListNode *i = head; i != NULL; i = i->next->next)
        {
            RandomListNode *temp = new RandomListNode(i->label);
            temp->next = i->next;
            i->next = temp;
        }
        for (RandomListNode *i = head; i != NULL;)
        {
            RandomListNode *copyNode = i->next;
            copyNode->random = (i->random == NULL ? NULL : i->random->next);
            i = copyNode->next;
            copyNode->next = (i == NULL ? NULL : i->next);
        }
        return head->next;
        // for (RandomListNode *i = head; i != NULL; i = i->next->next)
        //     i->next->random = (i->random == NULL ? NULL : i->random->next);
        // RandomListNode *oldList = head, *newList = head->next, *newHead = newList;
        // while (oldList != NULL)
        // {
        //     oldList->next = newList->next;
        //     oldList = oldList->next;
        //     newList->next = (oldList == NULL ? NULL : oldList->next);
        //     newList = newList->next;
        // }
        // return newHead;
    }
};