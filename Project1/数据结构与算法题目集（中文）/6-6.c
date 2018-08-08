#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
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
/*�������Ա���X��λ�á����Ҳ����򷵻�ERROR��*/
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
/*��X������λ��Pָ��Ľ��֮ǰ������true��
�������Pָ��Ƿ�λ�ã�
���ӡ��Wrong Position for Insertion��������false��*/
bool Insert(List L, ElementType X, Position P)
{
}
/*��λ��P��Ԫ��ɾ��������true��
������Pָ��Ƿ�λ�ã�
���ӡ��Wrong Position for Deletion��������false��*/
bool Delete(List L, Position P)
{
}