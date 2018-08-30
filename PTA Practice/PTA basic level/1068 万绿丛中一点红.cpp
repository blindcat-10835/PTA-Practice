/*
1068 万绿丛中一点红（20 point(s)）
对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。现给定一幅分辨率为 M×N 的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个相邻像素的颜色差充分大。

输入格式：
输入第一行给出三个正整数，分别是 M 和 N（≤ 1000），即图像的分辨率；以及 TOL，是所求像素点与相邻点的颜色差阈值，色差超过 TOL 的点才被考虑。随后 N 行，每行给出 M 个像素的颜色值，范围在 [0,2
​24
​​ ) 内。所有同行数字间用空格或 TAB 分开。

输出格式：
在一行中按照 (x, y): color 的格式输出所求像素点的位置以及颜色值，其中位置 x 和 y 分别是该像素在图像矩阵中的列、行编号（从 1 开始编号）。如果这样的点不唯一，则输出 Not Unique；如果这样的点不存在，则输出 Not Exist。

输入样例 1：
8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
输出样例 1：
(5, 3): 16711680
输入样例 2：
4 5 2
0 0 0 0
0 3 3 0
0 0 0 0
5 0 0 0
0 0 0 0
输出样例 2：
Not Unique
*/
#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int(*d)[1002] = new  int[1002][1002];
bool isGreatThanTOL(int a, int b, int tol)
{
	if (fabs(d[a][b] - d[a - 1][b]) <= tol) return false;
	if (fabs(d[a][b] - d[a - 1][b + 1]) <= tol) return false;
	if (fabs(d[a][b] - d[a - 1][b - 1]) <= tol) return false;
	if (fabs(d[a][b] - d[a][b + 1]) <= tol) return false;
	if (fabs(d[a][b] - d[a][b - 1]) <= tol) return false;
	if (fabs(d[a][b] - d[a + 1][b + 1]) <= tol) return false;
	if (fabs(d[a][b] - d[a + 1][b]) <= tol) return false;
	if (fabs(d[a][b] - d[a + 1][b - 1]) <= tol) return false;
	return true;
}
int main(int argc, char const *argv[])
{
	int M = 0, N = 0, delta = 0, c = 0, x = 0, y = 0;
	bool isRed = true;
	map <int, int> isUnique;

	scanf("%d %d %d", &M, &N, &delta);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &d[i][j]);
			isUnique[d[i][j]]++;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (isGreatThanTOL(i, j, delta) && isUnique[d[i][j]] == 1)
			{
				c++;
				x = i;
				y = j;
			}
		}
	}
	if (c == 1)
	{
		printf("(%d, %d): %d\n", y, x, d[x][y]);
	}
	else if (c == 0)
	{
		printf("Not Exist\n");
	}
	else
	{
		printf("Not Unique\n");
	}
	return 0;
}