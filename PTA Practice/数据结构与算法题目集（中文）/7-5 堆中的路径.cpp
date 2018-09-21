/*
7-5 堆中的路径（25 point(s)）
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:
5 3
46 23 26 24 10
5 4 3
输出样例:
24 23 10
46 23 10
26 10
*/

/*
小顶堆从1开始！！！
用数组表示
父子之间的序号为两倍关系
注意学习小顶堆的调整方法
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
using namespace std;

typedef int Elementtype;
typedef int PtrToTree;
const int MAXLENGTH = 1000;
const int null = 0;

//使用数组来表示树，则树根==序号，index == root;
struct TreeNode
{
	Elementtype Value = null;
	PtrToTree Left = null;
	PtrToTree Right = null;
};
const int INF = -10000 - 1;
int main(int argc, char const *argv[])
{
	int N = 1000, M = 1000;
	scanf("%d", &N);
	scanf("%d", &M);
	vector<int> MinHeap(N + 1, INF);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &MinHeap[i]);
		/*注意学习小顶堆的调整方法*/
		for (int j = 1; j <= i; j++)
		{
			if (MinHeap[j] < MinHeap[j / 2])
			{
				int tmp = MinHeap[j];
				MinHeap[j] = MinHeap[j / 2];
				MinHeap[j / 2] = tmp;
				j = 0;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		while (tmp != 1)
		{
			cout << MinHeap[tmp] << " ";
			tmp /= 2;
		}
		cout << MinHeap[tmp] << endl;
	}
	return 0;
}