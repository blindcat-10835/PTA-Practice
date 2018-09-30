#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
using namespace std;
const  int MAXNODE = 10;
/*
图的邻接矩阵表示
*/
int Graph[MAXNODE][MAXNODE];

bool isVisited[MAXNODE];
/*
图的深度优先搜索，
使用递归
*/
void DFS(int Root, int length)
{
	/*使用递归时，始终在外部定义isVisited*/
	isVisited[Root] = true;
	cout << Root << " ";
	for (int j = 0; j < length; j++)
	{
		if (Graph[Root][j] && isVisited[j] == false)
			DFS(j, length);
	}
	return;
}
/*
图的广度优先搜索，
使用队列,
*/
void BFS(int Root, int length)
{
	queue<int> Q;
	/*单独使用时，内部定义isVisited,计算连通图时，在外部定义*/
	vector<bool> isVisited(length, false);
	Q.push(Root);
	isVisited[Root] = true;
	while (!Q.empty())
	{
		cout << Q.front() << " ";
		for (int j = 0; j < length; j++)
		{
			if (Graph[Q.front()][j] && isVisited[j] == false)
			{
				Q.push(j);
				isVisited[j] = true;
			}
		}
		Q.pop();
	}
	return;
}
/*
计算图的连通子图数
*/
int CountConnectedGraph(int Root, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (!isVisited[i])
		{
			BFS(i, length);
			/*or use
			DFS(i,length);
			*/
			count++;
		}
	}
	return count;
}
/*
计算图的层数
*/
int CountLayer_BFS(int Root, int length, vector< vector<bool> > Graph)
{
	int LayerN = 0, LayerNBegin = Root, LayerNiEnd = Root, count = 0;
	vector<bool> isVisited(length, false);
	queue<int> Q;
	Q.push(Root);
	isVisited[Root] = true;
	while (!Q.empty())
	{
		for (int j = 0; j < length; j++)
		{
			if (Graph[Q.front()][j] && isVisited[j] == false)
			{
				Q.push(j);
				isVisited[j] = true;
				LayerNBegin = j;
			}
		}
		if (Q.front() == LayerNiEnd)
		{
			LayerN++;
			LayerNiEnd = LayerNBegin;
		}
		Q.pop();
		count++;
		if (LayerN > 6)
		{
			printf("%d: %.02f%%\n", Root + 1, count / double(length)*100.0);
			return LayerN;
		}
	}
	printf("%d: %.02f%%\n", Root + 1, count / double(length)*100.0);
	return LayerN;
}