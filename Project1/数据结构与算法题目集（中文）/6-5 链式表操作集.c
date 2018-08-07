#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/*返回线性表中首次出现X的位置。若找不到则返回ERROR；*/
Position Find(List L, ElementType X)
{
	int i = 1;
	while (X != L->Data)
	{
		i++;
		L = L->Next;
		if (L == NULL)return L;
	}
	return L->Data
}
/*将X插入在位置P指向的结点之前，
返回链表的表头。
如果参数P指向非法位置，
则打印“Wrong Position for Insertion”，
返回ERROR；*/
List Insert(List L, ElementType X, Position P)
{
	if (P <= 0 || L == NULL)
	{
		printf("Wrong Position for Insertion")；
			return ERROR;
	}
	Position temp = L;
	while (temp->Next != P)
	{
		temp = temp->Next;
		if (temp == NULL)
		{
			printf("Wrong Position for Insertion")；
				return ERROR;
		}
	}
	Position New = (Position)malloc(sizeof(struct LNode));
	temp->Next = New;
	New->Next = P;
	New->Data = X;
	return L;
}
/*将位置P的元素删除并返回链表的表头。
若参数P指向非法位置，
则打印“Wrong Position for Deletion”并返回ERROR。*/
List Delete(List L, Position P)
{
	if (P <= 0 || L == NULL)
	{
		printf("Wrong Position for Insertion")；
			return ERROR;
	}
	Position temp = L;
	while (temp->Next != P)
	{
		temp = temp->Next;
		if (temp == NULL)
		{
			printf("Wrong Position for Insertion")；
				return ERROR;
		}
	}
	temp->Next = P->Next;
	return L;
}