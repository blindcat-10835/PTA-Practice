/*
1012 数字分类 (20)（20 point(s)）
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；

A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

A3 = 被5除后余2的数字的个数；

A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

A5 = 被5除后余4的数字中最大数字。

输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：

30 11 2 9.7 9
输入样例2：

8 1 2 4 5 6 7 9 16
输出样例2：

N 11 2 N 9
*/
/*
1012 数字分类 (20)（20 分） - CSDN博客
https://blog.csdn.net/piaoliangjinjin/article/details/80742344
“这道题需要注意的是：A2。当“A2的结果是0” 的情况下，可能是没有符合条件的数据，也可能是有符合条件的数据，加加减减后的结果为0.应该分别的讨论。”
 这就是我最后一个点没通过的原因；
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, j, i = 0, k = 1;
	int A1 = 0, A2 = 0, A3 = 0, A5 = -1; float A4 = 0;
	cin >> n;
	int a2 = 0;
	while (n--)
	{
		cin >> j;
		if (j % 10 == 0)A1 += j;
		if (j % 5 == 1)
		{
			a2 = 1;
			A2 += (j*k); k = -k;
		}
		if (j % 5 == 2)
		{
			A3++;
		}
		if (j % 5 == 3)
		{
			A4 += j;
			i++;
		}
		if (j % 5 == 4 && A5 < j)
		{
			A5 = j;
		}
	}
	if (A1)cout << A1 << ' '; else cout << "N ";
	if (a2)cout << A2 << ' '; else cout << "N ";
	if (A3)cout << A3 << ' '; else cout << "N ";
	if (A4)printf("%.1f ", A4 / i); else cout << "N ";
	if (A5 != -1)cout << A5; else cout << "N";
	return 0;
}