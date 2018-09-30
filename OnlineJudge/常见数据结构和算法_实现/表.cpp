#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
using namespace std;
#define ERROR NULL
typedef int ElementType;
typedef struct LNode* PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;
struct LNode
{
	ElementType Data = 0;
	PtrToLNode Next = nullptr;
};
/*使用方式：	List Head = CreateNewNode();	*/
PtrToLNode CreateNewNode()
{
	PtrToLNode ret = (PtrToLNode)malloc(sizeof(LNode));
	ret->Next = nullptr;
	ret->Data = 0;
	return ret;
}

/*返回线性表中首次出现X的位置。若找不到则返回ERROR;*/
Position Find(List L, ElementType X)
{
	Position ret = L;
	while (ret != NULL && X != ret->Data)
	{
		ret = ret->Next;
	}
	if (ret == NULL)return ERROR;
	else return ret;
}
/*将X插入在位置P指向的结点之前，
返回链表的表头。
如果参数P指向非法位置，
则打印“Wrong Position for Insertion”，返回ERROR；*/
List Insert(List L, ElementType X, Position P)
{
	/*notice that there could be null,
	so comment these;
	if (P == NULL || L == NULL)	{printf("Wrong Position for Insertion");return ERROR;}
	*/
	Position temp = L;
	if (temp == P)
	{
		temp = (Position)malloc(sizeof(struct LNode));
		temp->Data = X;
		temp->Next = P;
		return temp;
	}
	while (temp != NULL && temp->Next != P)
	{
		temp = temp->Next;
	}
	if (temp == NULL)
	{
		printf("Wrong Position for Insertion\n");
		return ERROR;
	}
	else
	{
		Position New = (Position)malloc(sizeof(struct LNode));
		temp->Next = New;
		New->Next = P;
		New->Data = X;
		return L;
	}
}

/*将位置P的元素删除并返回链表的表头。
若参数P指向非法位置，
则打印“Wrong Position for Deletion”并返回ERROR。*/
List Delete(List L, Position P)
{
	if (P == L)
	{
		L = L->Next;
		return L;
	}
	Position temp = L;
	/*notice!:
	the order of these two "temp..."and"temp.next ..." is important
	*/
	while (temp != NULL && temp->Next != P)
	{
		temp = temp->Next;
	}
	if (temp == NULL)
	{
		printf("Wrong Position for Deletion\n");
		return ERROR;
	}
	else
	{
		temp->Next = P->Next;
		free(P);
		return L;
	}
}