List MakeEmpty()
{
	List p;
	p = (List)malloc(sizeof(struct LNode));
	p->Last = -1;//������lastΪ-1,��������lastÿ��ָ�ľ������һ�����ݣ���������һ�����ݵ���һ��
	return p;
}
Position Find(List L, ElementType X)
{
	int i;
	for (i = 0; i <= L->Last; i++)
	{
		if (X == L->Data[i])
		{//������������
			return i;
		}
	}
	return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
	if (L->Last == MAXSIZE - 1)
	{//������
		printf("FULL");
		return false;
	}
	if (P<0 || P>L->Last + 1)
	{//ֻ�ܲ鵽�������ֵ�λ�û����һ������һ��
		printf("ILLEGAL POSITION");
		return false;
	}
	int i;
	for (i = L->Last + 1; i > P; i--)
	{
		L->Data[i] = L->Data[i - 1];//����ƽ��
	}
	L->Data[i] = X;//����
	L->Last++;//��������
	return true;
}

bool Delete(List L, Position P)
{
	int i;
	//if(L->Last==-1)return false;//Ϊ�գ�������Ϊ��һ����һ�ٵ��жϵ���Ϊ��ʱӦ���emptyû���
	if (P<0 || P>L->Last)
	{//ɾ����λ�ò�������λ����
		printf("POSITION %d EMPTY", P);
		return false;
	}
	for (i = P; i < L->Last; i++)
	{//ɾ��������ƽ��
		L->Data[i] = L->Data[i + 1];
	}
	L->Last--;//����һ��
	return true;
}