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
/*����Insert��X�������������BST�����ؽ�����ĸ����ָ�룻*/
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
		return BST;
	}
}
/*����Delete��X�Ӷ���������BST��ɾ���������ؽ�����ĸ����ָ�룻���X�������У����ӡһ��Not Found������ԭ���ĸ����ָ�룻*/
BinTree Delete(BinTree BST, ElementType X)
{
	//note: this function always return the root of BST,
	//so dont change the BST pointer;
	if (BST == NULL)
	{
		printf("Not Found\n");
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
/*����Find�ڶ���������BST���ҵ�X�����ظý���ָ�룻����Ҳ����򷵻ؿ�ָ�룻*/
Position Find(BinTree BST, ElementType X)
{
	if (BST == NULL)
	{
		return NULL;
	}
	else if (BST->Data == X)
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
/*����FindMin���ض���������BST����СԪ����ָ�룻*/
Position FindMin(BinTree BST)
{
	if (BST == NULL)
	{
		return NULL;
	}
	else if (BST->Left != NULL)
	{
		return FindMin(BST->Left);
	}
	else
	{
		return BST;
	}
}
/*����FindMax���ض���������BST�����Ԫ����ָ�롣*/
Position FindMax(BinTree BST)
{
	if (BST == NULL)
	{
		return NULL;
	}
	else if (BST->Right != NULL)
	{
		return FindMax(BST->Right);
	}
	else
	{
		return BST;
	}
}