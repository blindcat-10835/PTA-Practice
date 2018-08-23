﻿/*
1025 反转链表（25 point(s)）
给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10
​5
​​ )、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：

Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
/*
dont ! use !!!cout!!!!!!!!!!!!
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
struct Node
{
	int Data = -1;
	int Next = 100000;
};

void Reverse(Node *List, int K)
{
	int P3, P2, P1;
	static int Head = 100000;
	int End = Head;
	for (int i = 0; i < K; i++)
	{
		End = List[End].Next;
	}
	P3 = P1 = List[Head].Next;
	List[Head].Next = End;
	P2 = List[End].Next;
	for (int i = 0; i < K; i++)
	{
		P1 = P2;
		P2 = P3;
		P3 = List[P3].Next;
		List[P2].Next = P1;
	}
	for (int i = 0; i < K; i++)
	{
		Head = List[Head].Next;
	}
}

int main(int argc, char const *argv[])
{
	int Address0, N, K;
	Node List[100001];
	cin >> Address0 >> N >> K;
	List[100000].Next = Address0;
	int address;
	/*input the List */
	for (int i = 0; i < N; i++)
	{
		cin >> address;
		cin >> List[address].Data >> List[address].Next;
	}
	/*count vivid N*/
	Address0 = List[100000].Next;
	for (N = 0; Address0 != -1; N++)
	{
		Address0 = List[Address0].Next;
	}

	/*reverse the List*/
	for (int i = 0; i < N - N % K; i += K)
	{
		Reverse(List, K);
	}

	/*print the List*/
	//cout << "**************" << endl;
	Address0 = List[100000].Next;
	for (int i = 0; List[Address0].Next != -1; i++)
	{
		printf("%05d %d %05d\n", Address0, List[Address0].Data, List[Address0].Next);
		/*cout.fill('0');
		cout.width(5);
		cout << Address0 << ' ';
		cout << List[Address0].Data << ' ';
		cout.fill('0');
		cout.width(5);
		cout << List[Address0].Next << endl;*/
		Address0 = List[Address0].Next;
	}
	//cout.fill('0');
	//cout.width(5);
	//cout << Address0 << ' ';
	//cout << List[Address0].Data << ' ';
	///*print address'-1'*/
	//cout << List[Address0].Next << endl;
	printf("%05d %d -1", Address0, List[Address0].Data);

	return 0;
}

//
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//const int maxn = 100005;
//int data[maxn];
//int list[maxn];
//int main()
//{
//	int next[maxn];
//	int first, k, n, temp, sum = 0;
//	scanf("%d%d%d", &first, &n, &k);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &temp);
//		scanf("%d %d", &data[temp], &next[temp]);
//	}
//	while (first != -1)
//	{
//		list[sum++] = first;
//		first = next[first];
//	}
//	for (int i = 0; i < (sum - sum % k); i += k)
//	{
//		reverse(begin(list) + i, begin(list) + i + k);
//	}
//	for (int i = 0; i < sum - 1; i++)
//	{
//		printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
//	}
//	printf("%05d %d -1", list[sum - 1], data[list[sum - 1]]);
//	return 0;
//}