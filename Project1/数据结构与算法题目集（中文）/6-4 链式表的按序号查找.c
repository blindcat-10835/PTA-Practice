#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth(List L, int K)
{
	if (K <= 0 || L == NULL)return ERROR;
	for (int i = 1; i < K; i++)
	{
		if (L->Next != NULL)L = L->Next;
		else	return ERROR;
	}
	return L->Data;
}

int main()
{
	int N, K;
	ElementType X;
	List L = Read();
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &K);
		X = FindKth(L, K);
		if (X != ERROR)
			printf("%d ", X);
		else
			printf("NA ");
	}
	return 0;
}

/* 你的代码将被嵌在这里 */