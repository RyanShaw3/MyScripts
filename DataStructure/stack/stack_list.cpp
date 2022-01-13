#include <stdio.h>
#include <stdlib.h>
#define ElementType int //设置栈储存元素的数据类型

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

//声明节点
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

//判断栈是否是空栈
int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

//创建一个空栈
Stack CreateStack(void)
{
    Stack S;
    S = (PtrToNode)malloc(sizeof(struct Node));
    if (S == NULL)
    {
        printf("Out of space!!!");
        return NULL;
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

//删除栈
void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

//清空栈
void MakeEmpty(Stack S)
{
    if (S == NULL)
        printf("Must use CreateStack first");
    else
        while (!IsEmpty(S))
            Pop(S);
}

//元素进栈
void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        printf("Out of space!!!");
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

//返回栈顶元素
ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    printf("Empty stack");
    return 0;
}

//从栈顶弹出元素
void Pop(Stack S)
{
    PtrToNode FirstCell;
    if (IsEmpty(S))
        printf("Empty stack");
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}