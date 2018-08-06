#ifndef _List_H

#include <stdio.h>
#include <stdlib.h>
#include "Cursor.h"
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif

struct Node
{
	ElementType Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;
}

List MakeEmpty(List L)
{
	L->Element = NULL;
	L->Next = NULL;
	return L;
}
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
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
Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	return P;
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		//FatalError("Out of space");
		printf("Out of space");
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

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

//typedef struct TNode *Position;
//typedef Position BinTree; /* 二叉树类型 */
//struct TNode
//{ /* 树结点定义 */
//	ElementType Data; /* 结点数据 */
//	BinTree Left;     /* 指向左子树 */
//	BinTree Right;    /* 指向右子树 */
//};