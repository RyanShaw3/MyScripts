#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MinQueueSize (5)

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

//声明节点
struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

//测试队列是否为空
int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

//测试队列是否已满
int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

//创建一个队列
Queue CreateQueue(int MaxElements)
{
    Queue Q;
    if (MaxElements < MinQueueSize)
    {
        printf("Queue size is too small");
        return NULL;
    }
    Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
    {
        printf("Out of space!!!");
        return NULL;
    }
    Q->Array = (ElementType *)malloc(sizeof(ElementType));
    if (Q->Array == NULL)
    {
        printf("Out of space!!!");
        return NULL;
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

//删除一个队列
void DisposeQueue(Queue Q)
{
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}

//构造空队列
void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

//入队
void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        printf("Full queue");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

//返回队列首的元素
ElementType Front(Queue Q)
{
    if (!IsEmpty(Q))
        return Q->Array[Q->Front];
    printf("Empty queue");
    return 0;
}

//出队
void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
        printf("Empty queue");
    else
    {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

//返回队首的元素并出队
ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = 0;
    if (IsEmpty(Q))
        printf("Empty queue");
    else
    {
        Q->Size--;
        X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
    }
    return X;
}