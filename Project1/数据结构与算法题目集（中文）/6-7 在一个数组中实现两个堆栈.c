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

/*ע�⣺�����ջ������Push�������������Stack Full�����ҷ���false��
���ĳ��ջ�ǿյģ���Pop�������������Stack Tag Empty��
������Tag�Ǹö�ջ�ı�ţ������ҷ���ERROR��*/
//�����ӿڶ��壺
//����Tag�Ƕ�ջ��ţ�ȡ1��2��MaxSize��ջ����Ĺ�ģ;
Stack CreateStack(int MaxSize)
{
	Stack ret = (Stack)malloc(sizeof(struct SNode));
	ret->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	ret->Top1 = -1;
	ret->Top2 = MaxSize;
	ret->MaxSize = MaxSize;
	return ret;
}
bool Push(Stack S, ElementType X, int Tag)
{
	if (S == NULL || (Tag != 1 && Tag != 2))
	{
		return false;
	}
	else if (S->Top1 + 1 == S->Top2)
	{
		printf("Stack Full\n");
		return false;
	}
	else if (Tag == 1)
	{
		S->Top1++;
		S->Data[S->Top1] = X;
		return true;
	}
	else if (Tag == 2)
	{
		S->Top2--;
		S->Data[S->Top2] = X;
		return true;
	}
}
ElementType Pop(Stack S, int Tag)
{
	if (S == NULL || (Tag != 1 && Tag != 2))
	{
		return ERROR;
	}
	else if (Tag == 1)
	{
		if (S->Top1 == -1)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR;
		}
		else
		{
			S->Top1--;
			return S->Data[S->Top1 + 1];
		}
	}
	else if (Tag == 2)
	{
		if (S->Top2 == S->MaxSize)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR;
		}
		else
		{
			S->Top2++;
			return S->Data[S->Top2 - 1];
		}
	}
}