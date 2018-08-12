BinTree Insert(BinTree BST, ElementType X)
{
	//�����һ���սڵ�
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));//��ȻΪ������Ҫ����һ��
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	}
	else
	{//һ�����
		if (X < BST->Data)
		{//����ֵС�ڽڵ㣬Ӧ��������������λ��
			BST->Left = Insert(BST->Left, X);//�ݹ����������
		}
		else if (X > BST->Data)
		{//����ֵ���ڽڵ㣬Ӧ��������������
			BST->Right = Insert(BST->Right, X);//�ݹ����������
		}
		//������˵��X�Ѿ����ڣ�ʲôҲ����
	}
	return BST;
}
Position Find(BinTree BST, ElementType X)
{
	while (BST)
	{//ֱ��ѭ�����ң���������
		if (X < BST->Data)
		{
			BST = BST->Left;//С�ڽڵ㣬��������
		}
		else if (X > BST->Data)
		{//���ڽڵ㣬��������
			BST = BST->Right;
		}
		else
		{//������ҵ�
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
		printf("Not Found\n");//���������Ϊ�գ�˵��û��
	}
	else
	{//���������ڲ����ص������ҵ�����ô��
		if (X < BST->Data)
		{
			BST->Left = Delete(BST->Left, X);//���������ݹ�ɾ��
		}
		else if (X > BST->Data)
		{
			BST->Right = Delete(BST->Right, X);//���������ݹ�ɾ��
		}
		else
		{//��ǰBST����Ҫɾ���Ľڵ�
			if (BST->Left && BST->Right)
			{//Ҫ��ɾ���Ľڵ��������������ӣ��ʹ�������������С�������ɾ���Ľڵ�
				temp = FindMin(BST->Right);//����С
				BST->Data = temp->Data;//���ɾ���Ľڵ�
				BST->Right = Delete(BST->Right, temp->Data);//ɾ�����������Ǹ��ڵ�
			}
			else
			{//ֻ��һ���ӽڵ�
				temp = BST;
				if (!BST->Left)
				{//ֻ���ҽڵ�
					BST = BST->Right;//ֱ�Ӹ�ֵ�Ϳ���
				}
				else if (!BST->Right)
				{//ֻ����ڵ�
					BST = BST->Left;//ֱ�Ӹ�ֵ�Ϳ���
				}
				free(temp);//���ɶҲû��ֱ��ɾ���Ϳ��ԣ���Ȼ�������������ֵ��ҲҪɾ��
			}
		}
	}
	return BST;
}