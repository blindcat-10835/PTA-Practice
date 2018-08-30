/*PAT Basic 1008. 数组元素循环右移问题 (20) - CSDN博客
https://blog.csdn.net/xtzmm1215/article/details/38407799

blindcat:
通读代码后发现，实际上只是做了3次中心对称，这样比较严格实现题目的要求，每个元素移动2次。总体2N次。
下面是自己试着用链表实现的代码；

*/
/*1008 数组元素循环右移问题 (20)（20 point(s)）
一个数组A中存有N（N&gt0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A~0~ A~1~……A~N-1~）变换为（A~N-M~ …… A~N-1~ A~0~ A~1~……A~N-M-1~）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。

输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例：

6 2
1 2 3 4 5 6
输出样例：

5 6 1 2 3 4
*/
#include <stdio.h>
int a[100];
void reverse(int *a, int m, int n)
{
	for (int i = m; i <= (m + n) / 2; i++)
	{
		int tmp = a[i];
		a[i] = a[m + n - i];
		a[m + n - i] = tmp;
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	m %= n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	reverse(a, 0, n - m - 1);
	reverse(a, n - m, n - 1);
	reverse(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d%s", a[i], (i - n + 1 ? " " : "\n"));
	return 0;
}
/*
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
List cinList(int length);
bool coutList(List l);
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	m %= n;
	List l = cinList(n);
	if (!m)
	{
		coutList(l); return 0;
	}
	Position tmp = l;
	for (int i = 1; i < n - m; i++)
	{
		tmp = tmp->Next;
	}
	Position rear = tmp;
	tmp = tmp->Next;
	List head = tmp;
	rear->Next = NULL;
	while (tmp->Next)
	{
		tmp = tmp->Next;
	}
	tmp->Next = l;
	l = head;
	coutList(l);
	return 0;
}

List cinList(int length)
{
	Position rear = (List)malloc(sizeof(struct LNode));
	rear->Next = NULL;
	List head = rear;
	while (length--)
	{
		rear->Next = (List)malloc(sizeof(struct LNode));
		rear = rear->Next;
		rear->Next = NULL;
		cin >> rear->Data;
	}
	rear = head;
	head = head->Next;
	free(rear);
	return head;
}
bool coutList(List l)
{
	while (l->Next)
	{
		cout << l->Data << ' ';;
		l = l->Next;
	}
	cout << l->Data;
	return true;
}
*/