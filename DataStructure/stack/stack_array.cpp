#include <stdio.h>
#include <stdlib.h>
#define ElementType int //设置栈储存元素的数据类型
#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

//声明节点
struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

//检测栈是否是空栈
int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

//检测栈是否已满
int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

//栈的创建
Stack CreateStack(int MaxElements)
{
    Stack S;
    if (MaxElements < MinStackSize)
    {
        printf("Stack size is too small");
        return NULL;
    }
    S = (Stack)malloc(sizeof(struct StackRecord));
    if (S == NULL)
    {
        printf("Out of space!!!");
        return NULL;
    }
    S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL)
    {
        printf("Out of space!!!");
        return NULL;
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}

//释放栈
void DisposeStack(Stack S)
{
    if (S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

//创建一个空栈
void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

//元素进栈
void Push(ElementType X, Stack S)
{
    if (IsFull(S))
        printf("Full stack");
    else
        S->Array[++S->TopOfStack] = X;
}

//返回栈顶元素
ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack];
    printf("Empty stack");
    return 0;
}

//从栈弹出元素
void Pop(Stack S)
{
    if (IsEmpty(S))
        printf("Empty stack");
    else
        S->TopOfStack--;
}

//给出栈顶元素并从栈弹出
ElementType TopAndPop(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    printf("Empty stack");
    return 0;
}