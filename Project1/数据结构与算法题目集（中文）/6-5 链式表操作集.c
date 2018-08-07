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
/*�������Ա����״γ���X��λ�á����Ҳ����򷵻�ERROR��*/
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
/*��X������λ��Pָ��Ľ��֮ǰ��
��������ı�ͷ��
�������Pָ��Ƿ�λ�ã�
���ӡ��Wrong Position for Insertion����
����ERROR��*/
List Insert(List L, ElementType X, Position P)
{
	if (P <= 0 || L == NULL)
	{
		printf("Wrong Position for Insertion")��
			return ERROR;
	}
	Position temp = L;
	while (temp->Next != P)
	{
		temp = temp->Next;
		if (temp == NULL)
		{
			printf("Wrong Position for Insertion")��
				return ERROR;
		}
	}
	Position New = (Position)malloc(sizeof(struct LNode));
	temp->Next = New;
	New->Next = P;
	New->Data = X;
	return L;
}
/*��λ��P��Ԫ��ɾ������������ı�ͷ��
������Pָ��Ƿ�λ�ã�
���ӡ��Wrong Position for Deletion��������ERROR��*/
List Delete(List L, Position P)
{
	if (P <= 0 || L == NULL)
	{
		printf("Wrong Position for Insertion")��
			return ERROR;
	}
	Position temp = L;
	while (temp->Next != P)
	{
		temp = temp->Next;
		if (temp == NULL)
		{
			printf("Wrong Position for Insertion")��
				return ERROR;
		}
	}
	temp->Next = P->Next;
	return L;
}