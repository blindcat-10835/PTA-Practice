/*
1013 Battle Over Cities（25 point(s)）
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city
​1
​​ -city
​2
​​  and city
​1
​​ -city
​3
​​ . Then if city
​1
​​  is occupied by the enemy, we must have 1 highway repaired, that is the highway city
​2
​​ -city
​3
​​ .

Input Specification:
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output Specification:
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input:
3 2 3
1 2
1 3
1 2 3
Sample Output:
1
0
0
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int N = 1001;

int graph[N][N] = { 0 };
bool isVisited[N] = { false };
void dfs(int d)
{
	isVisited[d] = true;
	for (int i = 1; i <= N; i++)
	{
		if (graph[d][i] == 1 && !isVisited[i])
		{
			isVisited[i] = true;
			dfs(i);
		}
	}
}

int main(int argc, char const *argv[])
{
	int  City, Edge, k;
	cin >> City >> Edge >> k;
	for (int i = 0; i < Edge; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
	for (int i = 0; i < k; i++)
	{
		int a = 0;
		scanf("%d", &a);
		fill(&isVisited[1], &isVisited[City + 1], false);
		isVisited[a] = true;
		int number = 0;
		for (int j = 1; j <= City; j++)
		{
			if (!isVisited[j])
			{
				dfs(j);
				number++;
			}
		}
		printf("%d\n", number - 1);
	}
	return 0;
}