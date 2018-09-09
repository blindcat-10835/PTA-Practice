/*
1018
1017
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
	int root = 0;
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
	int root = BuildTree(S1, Tree, length);
	vector<bool> isVisited(length, false);
	for (int i = 0; i < length; i++)
	{
		int j = root;
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