#include <iostream>
#include <vector>
using namespace std;

typedef struct Node
{
    int val;
    struct Node *prev, *next;
    Node(int _val) : val(_val), prev(nullptr), next(nullptr) {}
} Node;
class MyCircularDeque
{
private:
    Node *head, *tail;
    int capacity;
    int size;

public:
    MyCircularDeque(int k) : capacity(k), size(0), head(nullptr), tail(nullptr)
    {
    }

    bool insertFront(int value)
    {
        if (size == capacity)
            return false;
        Node *node = new Node(value);
        if (size == 0)
            head = tail = node;
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (size == capacity)
            return false;
        Node *node = new Node(value);
        if (size == 0)
            head = tail = node;
        else
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (size == 0)
            return false;
        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete temp;
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (size == 0)
            return false;
        Node *temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        delete temp;
        size--;
        return true;
    }

    int getFront()
    {
        if (size == 0)
            return -1;
        return head->val;
    }

    int getRear()
    {
        if (size == 0)
            return -1;
        return tail->val;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */