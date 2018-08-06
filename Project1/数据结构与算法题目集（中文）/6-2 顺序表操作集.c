#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum { false, true } bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode
{
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty()
{
	List ret = (List)malloc(sizeof(struct LNode));
	ret->Last = ERROR;
	return ret;
}

Position Find(List L, ElementType X)
{
	Position i = 0;
	while (1)
	{
		if (L->Data[i] == X)return i;
		i++;
		if (i > L->Last)return ERROR;
	}
}

bool Insert(List L, ElementType X, Position P)
{
	ElementType temp;
	if (L->Last >= MAXSIZE - 1)
	{
		printf("FULL");
		return false;
	}
	if (P<0 || P>L->Last + 1)
	{
		printf("ILLEGAL POSITION");
		return false;
	}

	for (int i = P; i <= L->Last + 1; i++)
	{
		temp = L->Data[i];
		L->Data[i] = X;
		X = temp;
	}
	L->Last++;
	return true;
}

bool Delete(List L, Position P)
{
	if (P < 0 || P > L->Last)
	{
		printf("POSITION %d EMPTY", P);
		return false;
	}
	int i;
	for (i = P; i < L->Last; i++)
	{
		L->Data[i] = L->Data[i + 1];
	}
	L->Last--;
	return true;
}

int main()
{
	List L;
	ElementType X;
	Position P;
	int N;

	L = MakeEmpty();
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &X);
		if (Insert(L, X, 0) == false)
			printf(" Insertion Error: %d is not in.\n", X);
	}
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else
			printf("%d is at position %d.\n", X, P);
	}
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &P);
		if (Delete(L, P) == false)
			printf(" Deletion Error.\n");
		if (Insert(L, 0, P) == false)
			printf(" Insertion Error: 0 is not in.\n");
	}
	return 0;
}

/* 你的代码将被嵌在这里 */