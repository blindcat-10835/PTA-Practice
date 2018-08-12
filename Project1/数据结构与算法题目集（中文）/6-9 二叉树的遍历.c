#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);
void InorderTraversal(BinTree BT)//the tree node is in the middle;
{
	if (BT == NULL)return;
	else
	{
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);
		InorderTraversal(BT->Right);
		return;
	}
}
void PreorderTraversal(BinTree BT)
{
	if (BT == NULL)return;
	else
	{
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
		return;
	}
}
void PostorderTraversal(BinTree BT)
{
	if (BT == NULL)return;
	else
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
		return;
	}
}
void LevelorderTraversal(BinTree BT)
{
	if (BT != NULL)
	{
		BinTree sequence[100] = { NULL };//Note that this initialization is critical
		int print = 0, wait = 1;
		sequence[print] = BT;
		while (sequence[print] != NULL)//related to the initialization
		{
			BinTree temp = sequence[print++];
			printf(" %c", temp->Data);
			if (temp->Left != NULL)sequence[wait++] = temp->Left;
			if (temp->Right != NULL)sequence[wait++] = temp->Right;
		}
	}
}