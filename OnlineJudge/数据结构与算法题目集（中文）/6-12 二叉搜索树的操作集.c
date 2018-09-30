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

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */
/*函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；*/
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
/*函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；*/
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
			/* 被删除结点有一个或无子结点 */
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
/*函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；*/
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
/*函数FindMin返回二叉搜索树BST中最小元结点的指针；*/
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
/*函数FindMax返回二叉搜索树BST中最大元结点的指针。*/
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