/*
7-4 是否同一棵二叉搜索树（25 point(s)）
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
Yes
No
No
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
const int null = -1;

//使用数组来表示树，则树根==序号，index == root;
struct TreeNode
{
	Elementtype Value = null;
	PtrToTree Left = null;
	PtrToTree Right = null;
};

PtrToTree BuildTree(vector<int> Senquence, vector<TreeNode> &Tree, int length)
{
	PtrToTree root = 0;
	for (int i = 0; i < length; i++)
	{
		Tree[i].Value = Senquence[i];
	}
	for (int i = 1; i < length; i++)
	{
		int j = 0;
		while (true)
		{
			if (Senquence[i] < Tree[j].Value)
			{
				if (Tree[j].Left != null)
				{
					j = Tree[j].Left;
				}
				else
				{
					Tree[j].Left = i;
					break;
				}
			}
			else
			{
				if (Tree[j].Right != null)
				{
					j = Tree[j].Right;
				}
				else
				{
					Tree[j].Right = i;
					break;
				}
			}
		}
	}
	return root;
}
bool isTheSameBST(vector<int> S1, vector<int> S2, int length)
{
	vector<TreeNode> Tree(length);
	PtrToTree root = BuildTree(S1, Tree, length);
	vector<bool> isVisited(length, false);
	for (int i = 0; i < length; i++)
	{
		PtrToTree j = root;
		while (S2[i] != Tree[j].Value&& j != null)
		{
			if (isVisited[j] == false)return false;
			if (S2[i] < Tree[j].Value)
			{
				j = Tree[j].Left;
			}
			else
			{
				j = Tree[j].Right;
			}
		}
		isVisited[j] = true;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int N = 10, L;
	vector<int> Sequence(N), ToBeCompare(N);
	while (true)
	{
		scanf("%d", &N);
		if (N == 0)break;
		scanf("%d", &L);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &Sequence[i]);
		}
		for (int i = 0; i < L; i++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf("%d", &ToBeCompare[k]);
			}
			if (isTheSameBST(Sequence, ToBeCompare, N))
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
	}
	return 0;
}