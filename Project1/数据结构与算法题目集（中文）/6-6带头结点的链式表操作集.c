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

/*����������һ���յ����Ա�*/
List MakeEmpty()
{
	List ret = (List)malloc(sizeof(struct LNode));
	ret->Data = 0;
	ret->Next = NULL;
	return ret;
}
/*�������Ա���X��λ�á����Ҳ����򷵻�false��*/
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
/*��X������λ��Pָ��Ľ��֮ǰ������true��
�������Pָ��Ƿ�λ�ã�
���ӡ��Wrong Position for Insertion��������false��*/
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
/*��λ��P��Ԫ��ɾ��������true��
������Pָ��Ƿ�λ�ã�
���ӡ��Wrong Position for Deletion��������false��*/
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