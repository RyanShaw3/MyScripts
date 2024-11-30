#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
private:
    vector<int> q;
    int capacity;
    int front;
    int rear;

public:
    MyCircularQueue(int k)
    {
        this->capacity = k + 1;
        this->front = this->rear = 0;
        this->q = vector<int>(this->capacity);
    }

    bool enQueue(int value)
    {
        if (this->isFull())
            return false;
        this->q[this->rear] = value;
        this->rear = (this->rear + 1) % this->capacity;
        return true;
    }

    bool deQueue()
    {
        if (this->isEmpty())
            return false;
        this->front = (this->front + 1) % this->capacity;
        return true;
    }

    int Front()
    {
        if (this->isEmpty())
            return -1;
        return this->q[this->front];
    }

    int Rear()
    {
        if (this->isEmpty())
            return -1;
        return this->q[(this->rear + this->capacity - 1) % this->capacity];
    }

    bool isEmpty()
    {
        return this->front == this->rear;
    }

    bool isFull()
    {
        return this->front == (this->rear + 1) % this->capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */