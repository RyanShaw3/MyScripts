#include <stdio.h>
#include <stdlib.h>
#define ElementType int //设置链表储存元素的数据类型

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

//声明节点
struct Node
{
    ElementType Element;
    Position Next;
};

//清空一个链表
List MakeEmpty(List L)
{
    if (L != NULL)
        DeleteList(L);
    L = (PtrToNode)malloc(sizeof(struct Node));
    if (L == NULL)
    {
        printf("Out of space!!!");
        return L;
    }
    L->Next = NULL;
    return L;
}

//测试一个链表是否是空表的函数
int IsEmpty(List L)
{
    return L->Next == NULL;
}

//测试当前的元素是否是链表的最后一个元素
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

//在链表中查找给定的某个元素，并返回它的位置
Position Find(ElementType X, List L)
{
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

//删除链表中的某个元素
void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

//在链表中查找给定的某个元素，并返回它的前一个位置
Position FindPrevious(ElementType X, List L)
{
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

//在链表的指定位置插入指定的某个元素
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("Out of space!!!");
        return;
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

//删除一个链表
void DeleteList(List L)
{
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

//返回链表的头节点
Position Header(List L)
{
    return L;
}

//返回链表的第一个节点
Position First(List L)
{
    return L->Next;
}

//返回当前节点的下一个节点
Position Advance(Position P)
{
    return P->Next;
}

//返回当前节点储存的元素
ElementType Retrieve(Position P)
{
    return P->Element;
}