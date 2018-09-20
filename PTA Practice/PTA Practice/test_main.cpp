#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
using namespace std;
typedef int ElementType;
typedef struct LNode* PtrToLNode;
typedef PtrToLNode List;
struct LNode
{
	ElementType Value = 0;
	PtrToLNode Next = nullptr;
};

PtrToLNode CreateNewNode()
{
	PtrToLNode ret = (PtrToLNode)malloc(sizeof(LNode));
	ret->Next = nullptr;
	ret->Value = 0;
	return ret;
}
int main(int argc, char const *argv[])
{
	int N;
	List Head = CreateNewNode();
	PtrToLNode Tail = Head, K = Head;
	scanf("%d", &N);
	N -= 1;/*倒数第一个与tail是一致的*/
	while (true)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp < 0)break;
		Tail->Next = CreateNewNode();
		Tail = Tail->Next;
		Tail->Value = tmp;
		if (N)N--;
		else K = K->Next;
	}
	PtrToLNode Tmp = Head;
	Head = Head->Next;
	if (K != Tmp)
	{
		cout << K->Value;
	}
	else
	{
		cout << "NULL\n";
	}
	free(Tmp);
	return 0;
}