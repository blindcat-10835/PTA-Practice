#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT); /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */
void InorderTraversal(BinTree BT);  /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */

BinTree Insert(BinTree BST, ElementType X)
{
	if (BST == NULL)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
		return BST;
	}
	else if (X > BST->Data)
	{
		BST->Right = Insert(BST->Right, X);
		return BST;
	}
	else if (X < BST->Data)
	{
		BST->Left = Insert(BST->Left, X);
		reutrn BST;
	}
}
BinTree Delete(BinTree BST, ElementType X)
{
	//note: this function always return the root of BST,
	//so dont change the BST pointer;
	if (BST == NULL)
	{
		return BST;
	}
	else if (X > BST->Data)
	{
		BST->Right = Delete(BST->Right, X);
		return BST;
	}
	else if (X < BST->Data)
	{
		BST->Left = Delete(BST->Left, X);
		return BST;
	}
	else if (X == BST->Data)
	{
		if (BST->Left && BST->Right)
		{
			BST->Data = FindMax(BST->Left)->Data;
			BST->Left = Delete(BST->Left, BST->Data);
			return BST;
		}
		else
		{
			/* ��ɾ�������һ�������ӽ�� */
			if (BST->Left)
			{
				Position ret = BST->Left;
				free(BST);
				return ret;
			}
			else if (BST->Right)
			{
				Position ret = BST->Right;
				free(BST);
				return ret;
			}
		}
	}
}
Position Find(BinTree BST, ElementType X)
{
	if (BST->Data == X)
	{
		return BST;
	}
	else if (X > BST->Data)
	{
		return Find(BST->Right, X);
	}
	else if (X < BST->Data)
	{
		return Find(BST->Left, X);
	}
}
Position FindMin(BinTree BST)
{
	if (BST == NULL)
	{
	}
}
Position FindMax(BinTree BST);