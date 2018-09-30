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
void PreorderPrintLeaves(BinTree BT);

void PreorderPrintLeaves(BinTree BT)
{
	if (BT == NULL)return;
	else
	{
		if (BT->Left == NULL && BT->Right == NULL)printf(" %c", BT->Data);
		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);
		return;
	}
}