#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode
{
	ElementType *Data;
	Position Top1, Top2;
	int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->MaxSize = MaxSize;
	S->Data = (ElementType *)malloc(sizeof(ElementType)*MaxSize);
	S->Top2 = MaxSize;
	S->Top1 = -1;
	return S;
}
bool Push(Stack S, ElementType X, int Tag)
{
	if (S == NULL)
		return false;
	if ((S->Top1 + 1) == S->Top2)
	{
		printf("Stack Full\n");
		return false;
	}
	if (1 == Tag)
	{
		S->Data[++(S->Top1)] = X;
		return true;
	}
	else if (2 == Tag)
	{
		S->Data[(--S->Top2)] = X;
		return true;
	}
	return false;
}
ElementType Pop(Stack S, int Tag)
{
	if (S == NULL)
		return ERROR;
	if (1 == Tag)
	{
		if (-1 == S->Top1)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR;
		}
		return S->Data[(S->Top1)--];
	}
	else if (2 == Tag)
	{
		if (S->MaxSize == S->Top2)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR;
		}
		return S->Data[(S->Top2)++];
	}
	return ERROR;
}