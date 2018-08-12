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
int GetHeight(BinTree BT)
{
	if (BT == NULL)return 0;
	else
	{
		int l = GetHeight(BT->Left);
		int r = GetHeight(BT->Right);
		return  l > r ? l + 1 : r + 1;
	}
}