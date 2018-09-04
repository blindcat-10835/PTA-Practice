/*
1003 Emergency（25 point(s)）
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input Specification:
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C​1​​  and C​2
​​  - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c​1
​​ , c​2
​​  and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C​1
​​  to C​2
​​ .

Output Specification:
For each test case, print in one line two numbers: the number of different shortest paths between C​1
​​  and C​2
​​ , and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output:
2 4
*/
/*
blindcat：
学习fill的使用！

学习用邻接矩阵表示图！！

学习点权图！ 边权图！
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int N = 500;
const int INF = 10000000;

int EdgeWeight[N][N], NodeWeight[N];
bool isVisited[N];

int Count_Ways_to_Ni[N];
int Distance_NBegin_to_Ni[N];
int Sum_Of_NodeWeight_to_Ni[N];

int main(int argc, char const *argv[])
{
	fill(&EdgeWeight[0][0], &EdgeWeight[N][N], INF);
	fill(&Distance_NBegin_to_Ni[0], &Distance_NBegin_to_Ni[N], INF);
	int Node, Edge, NBegin, NEnd;
	cin >> Node >> Edge >> NBegin >> NEnd;
	for (int i = 0; i < Node; i++)
	{
		scanf("%d", &NodeWeight[i]);
	}
	for (int i = 0; i < Edge; i++)
	{
		int node1, node2, distance1_2;
		scanf("%d%d%d", &node1, &node2, &distance1_2);
		EdgeWeight[node1][node2] = EdgeWeight[node2][node1] = distance1_2;
	}
	/*for begin*/
	Distance_NBegin_to_Ni[NBegin] = 0;//把起点设为最近点
	Sum_Of_NodeWeight_to_Ni[NBegin] = NodeWeight[NBegin];
	Count_Ways_to_Ni[NBegin] = 1;

	/*计算最短路径的长度*/
	for (int j = 0; j < Node; j++)
	{
		/*1在未处理的结点中找到离起点最近的结点minNode*/
		int minDis = INF;
		int minNode = -1;
		for (int i = 0; i < Node; i++)
		{
			if (!isVisited[i] && Distance_NBegin_to_Ni[i] < minDis)
			{
				minNode = i;
				minDis = Distance_NBegin_to_Ni[i];
			}
		}
		if (minNode == -1)
		{
			break;//所有的结点都已经访问过了
		}

		/*2更新从 起点 到 那个结点的所有邻居 的距离*/
		for (int i = 0; i < Node; i++)
		{
			if (EdgeWeight[minNode][i] != INF)
			{
				if (Distance_NBegin_to_Ni[minNode] + EdgeWeight[minNode][i] < Distance_NBegin_to_Ni[i])
				{
					Distance_NBegin_to_Ni[i] = Distance_NBegin_to_Ni[minNode] + EdgeWeight[minNode][i];
					Count_Ways_to_Ni[i] = Count_Ways_to_Ni[minNode];
					Sum_Of_NodeWeight_to_Ni[i] = NodeWeight[i] + Sum_Of_NodeWeight_to_Ni[minNode];
				}
				else if (Distance_NBegin_to_Ni[minNode] + EdgeWeight[minNode][i] == Distance_NBegin_to_Ni[i])
				{
					Count_Ways_to_Ni[i] += Count_Ways_to_Ni[minNode];
					int tmp = NodeWeight[i] + Sum_Of_NodeWeight_to_Ni[minNode];
					Sum_Of_NodeWeight_to_Ni[i] = Sum_Of_NodeWeight_to_Ni[i] > tmp ? Sum_Of_NodeWeight_to_Ni[i] : tmp;
				}
			}
		}
		/*3当前结点已经访问*/
		isVisited[minNode] = true;
		/*回到1*/
	}

	//cout << Distance_NBegin_to_Ni[NEnd] << endl;
	cout << Count_Ways_to_Ni[NEnd] << ' ';
	cout << Sum_Of_NodeWeight_to_Ni[NEnd] << endl;
	return 0;
}