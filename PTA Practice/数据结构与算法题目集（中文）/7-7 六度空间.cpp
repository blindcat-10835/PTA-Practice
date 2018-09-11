/*
7-7 六度空间（30 point(s)）
“六度空间”理论又称作“六度分隔（Six Degrees of Separation）”理论。这个理论可以通俗地阐述为：“你和任何一个陌生人之间所间隔的人不会超过六个，也就是说，最多通过五个人你就能够认识任何一个陌生人。”如图1所示。

图1 六度空间示意图
“六度空间”理论虽然得到广泛的认同，并且正在得到越来越多的应用。但是数十年来，试图验证这个理论始终是许多社会学家努力追求的目标。然而由于历史的原因，这样的研究具有太大的局限性和困难。随着当代人的联络主要依赖于电话、短信、微信以及因特网上即时通信等工具，能够体现社交网络关系的一手数据已经逐渐使得“六度空间”理论的验证成为可能。

假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

输入格式:
输入第1行给出两个正整数，分别表示社交网络图的结点数N（1<N≤10
​4
​​ ，表示人数）、边数M（≤33×N，表示社交关系数）。随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到N编号）。

输出格式:
对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。

输入样例:
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
输出样例:
1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%
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

void BFS(int Root, int length, vector< vector<bool> > Graph)
{
	int Distance = 0, LayerDis_iBegin = Root, LayerDis_iEnd = Root, count = 0;
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
				LayerDis_iBegin = j;
			}
		}
		if (Q.front() == LayerDis_iEnd)
		{
			Distance++;
			LayerDis_iEnd = LayerDis_iBegin;
		}
		Q.pop();
		count++;
		if (Distance > 6)
		{
			printf("%d: %.02f%%\n", Root + 1, count / double(length)*100.0);
			return;
		}
	}
	printf("%d: %.02f%%\n", Root + 1, count / double(length)*100.0);
	return;
}
int main(int argc, char const *argv[])
{
	int N = 10000, E = 33 * 10000;
	cin >> N >> E;
	vector< vector<bool> > Graph(N, vector<bool>(N, false));
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		Graph[a - 1][b - 1] = Graph[b - 1][a - 1] = true;
	}

	for (int i = 0; i < N; i++)
	{
		BFS(i, N, Graph);
	}

	return 0;
}