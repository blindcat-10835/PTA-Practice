List MakeEmpty()
{
	List p;
	p = (List)malloc(sizeof(struct LNode));
	p->Last = -1;//这里令last为-1,这样可以last每次指的就是最后一个数据，而不是下一个数据的下一个
	return p;
}
Position Find(List L, ElementType X)
{
	int i;
	for (i = 0; i <= L->Last; i++)
	{
		if (X == L->Data[i])
		{//遍历搜索查找
			return i;
		}
	}
	return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
	if (L->Last == MAXSIZE - 1)
	{//容量慢
		printf("FULL");
		return false;
	}
	if (P<0 || P>L->Last + 1)
	{//只能查到已有数字的位置或最后一个的下一个
		printf("ILLEGAL POSITION");
		return false;
	}
	int i;
	for (i = L->Last + 1; i > P; i--)
	{
		L->Data[i] = L->Data[i - 1];//向右平移
	}
	L->Data[i] = X;//插入
	L->Last++;//个数增加
	return true;
}

bool Delete(List L, Position P)
{
	int i;
	//if(L->Last==-1)return false;//为空！！！因为这一句多此一举的判断导致为空时应输出empty没输出
	if (P<0 || P>L->Last)
	{//删除的位置不在已有位置内
		printf("POSITION %d EMPTY", P);
		return false;
	}
	for (i = P; i < L->Last; i++)
	{//删除后向左平移
		L->Data[i] = L->Data[i + 1];
	}
	L->Last--;//减少一个
	return true;
}