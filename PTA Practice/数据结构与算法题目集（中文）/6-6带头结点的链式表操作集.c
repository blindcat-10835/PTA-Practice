#include <stdio.h>
#include <stdlib.h>

#define false NULL
typedef enum { false, true } bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

/*创建并返回一个空的线性表；*/
List MakeEmpty()
{
	List ret = (List)malloc(sizeof(struct LNode));
	ret->Data = 0;
	ret->Next = NULL;
	return ret;
}
/*返回线性表中X的位置。若找不到则返回false；*/
Position Find(List L, ElementType X)
{
	Position ret = L;
	while (ret != NULL && X != ret->Data)
	{
		ret = ret->Next;
	}
	if (ret == NULL)return false;
	else return ret;
}
/*将X插入在位置P指向的结点之前，返回true。
如果参数P指向非法位置，
则打印“Wrong Position for Insertion”，返回false；*/
bool Insert(List L, ElementType X, Position P)
{
	Position temp = L;
	/********************************
	notice that there differs to ListWithoutHeader,
	because if P==header, it will go to"temp==null"finally
	*********************************
	if (temp == P)
	{
		printf("Wrong Position for Insertion\n");
		return false;
	}*/
	while (temp != NULL && temp->Next != P)
	{
		temp = temp->Next;
	}

	/*notice there couldnt be "temp.next==p"
	because null dont have "next'*/
	if (temp == NULL)
	{
		printf("Wrong Position for Insertion\n");
		return false;
	}
	else
	{
		Position New = (Position)malloc(sizeof(struct LNode));
		temp->Next = New;
		New->Next = P;
		New->Data = X;
		return true;
	}
}
/*将位置P的元素删除并返回true。
若参数P指向非法位置，
则打印“Wrong Position for Deletion”并返回false。*/
bool Delete(List L, Position P)
{
	Position temp = L;
	while (temp != NULL && temp->Next != P)
	{
		temp = temp->Next;
	}
	if (temp == NULL)
	{
		printf("Wrong Position for Deletion\n");
		return false;
	}
	else
	{
		temp->Next = P->Next;
		free(P);
		return true;
	}
}