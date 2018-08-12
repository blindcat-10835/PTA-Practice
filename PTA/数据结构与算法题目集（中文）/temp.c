BinTree Insert(BinTree BST, ElementType X)
{
	//如果是一个空节点
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));//既然为空所以要生成一个
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	}
	else
	{//一般情况
		if (X < BST->Data)
		{//插入值小于节点，应该往左子树中找位置
			BST->Left = Insert(BST->Left, X);//递归插入左子树
		}
		else if (X > BST->Data)
		{//插入值大于节点，应该往右子树中找
			BST->Right = Insert(BST->Right, X);//递归插入右子树
		}
		//如果相等说明X已经存在，什么也不做
	}
	return BST;
}
Position Find(BinTree BST, ElementType X)
{
	while (BST)
	{//直接循环查找，类似链表
		if (X < BST->Data)
		{
			BST = BST->Left;//小于节点，找左子树
		}
		else if (X > BST->Data)
		{//大于节点，找右子树
			BST = BST->Right;
		}
		else
		{//相等则找到
			return BST;
		}
	}
	return NULL;
}
Position FindMin(BinTree BST)
{
	if (!BST)
	{
		return NULL;
	}
	else if (!BST->Left)
		return BST;
	else return FindMin(BST->Left);
}
Position FindMax(BinTree BST)
{
	if (!BST)return NULL;
	else if (!BST->Right)return BST;
	else return FindMax(BST->Right);
}
BinTree Delete(BinTree BST, ElementType X)
{
	Position temp;
	if (!BST)
	{
		printf("Not Found\n");//如果最终树为空，说明没有
	}
	else
	{//这里类似于插入重点在于找到后怎么办
		if (X < BST->Data)
		{
			BST->Left = Delete(BST->Left, X);//从左子树递归删除
		}
		else if (X > BST->Data)
		{
			BST->Right = Delete(BST->Right, X);//从右子树递归删除
		}
		else
		{//当前BST就是要删除的节点
			if (BST->Left && BST->Right)
			{//要被删除的节点有左右两个孩子，就从右子树中找最小的数填充删除的节点
				temp = FindMin(BST->Right);//找最小
				BST->Data = temp->Data;//填充删除的节点
				BST->Right = Delete(BST->Right, temp->Data);//删除拿来填充的那个节点
			}
			else
			{//只有一个子节点
				temp = BST;
				if (!BST->Left)
				{//只有右节点
					BST = BST->Right;//直接赋值就可以
				}
				else if (!BST->Right)
				{//只有左节点
					BST = BST->Left;//直接赋值就可以
				}
				free(temp);//如果啥也没有直接删除就可以，当然上面两种情况赋值后也要删除
			}
		}
	}
	return BST;
}