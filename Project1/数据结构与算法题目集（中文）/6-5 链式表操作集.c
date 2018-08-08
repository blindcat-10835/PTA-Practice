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

/*�������Ա����״γ���X��λ�á����Ҳ����򷵻�ERROR;*/
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
/*��X������λ��Pָ��Ľ��֮ǰ��
��������ı�ͷ��
�������Pָ��Ƿ�λ�ã�
���ӡ��Wrong Position for Insertion��������ERROR��*/
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

/*��λ��P��Ԫ��ɾ������������ı�ͷ��
������Pָ��Ƿ�λ�ã�
���ӡ��Wrong Position for Deletion��������ERROR��*/
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