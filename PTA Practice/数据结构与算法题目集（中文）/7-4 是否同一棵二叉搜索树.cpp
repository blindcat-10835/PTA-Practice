/*
7-4 �Ƿ�ͬһ�ö�����������25 point(s)��
����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������

�����ʽ:
�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L����Ҫ�������С�

����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����

�����ʽ:
��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����

��������:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
�������:
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

//ʹ����������ʾ����������==��ţ�index == root;
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