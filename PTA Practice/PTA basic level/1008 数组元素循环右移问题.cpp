/*PAT Basic 1008. ����Ԫ��ѭ���������� (20) - CSDN����
https://blog.csdn.net/xtzmm1215/article/details/38407799

blindcat:
ͨ��������֣�ʵ����ֻ������3�����ĶԳƣ������Ƚ��ϸ�ʵ����Ŀ��Ҫ��ÿ��Ԫ���ƶ�2�Ρ�����2N�Ρ�
�������Լ�����������ʵ�ֵĴ��룻

*/
/*1008 ����Ԫ��ѭ���������� (20)��20 point(s)��
һ������A�д���N��N&gt0�����������ڲ�����ʹ�����������ǰ���£���ÿ������ѭ��������M��M>=0����λ�ã�����A�е������ɣ�A~0~ A~1~����A~N-1~���任Ϊ��A~N-M~ ���� A~N-1~ A~0~ A~1~����A~N-M-1~�������M����ѭ��������ǰ���M��λ�ã��������Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����

�����ʽ��ÿ���������һ��������������1������N ( 1<=N<=100)��M��M>=0������2������N��������֮���ÿո�ָ���

�����ʽ����һ�������ѭ������Mλ�Ժ���������У�֮���ÿո�ָ������н�β�����ж���ո�

����������

6 2
1 2 3 4 5 6
���������

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