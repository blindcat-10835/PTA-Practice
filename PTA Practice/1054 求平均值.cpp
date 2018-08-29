﻿/*
1054 求平均值（20 point(s)）
本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：
输入第一行给出正整数 N（≤100）。随后一行给出 N 个实数，数字间以一个空格分隔。

输出格式：
对每个非法输入，在一行中输出 ERROR: X is not a legal number，其中 X 是输入。最后在一行中输出结果：The average of K numbers is Y，其中 K 是合法输入的个数，Y 是它们的平均值，精确到小数点后 2 位。如果平均值无法计算，则用 Undefined 替换 Y。如果 K 为 1，则输出 The average of 1 number is Y。

输入样例 1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例 1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例 2：
2
aaa -9999
输出样例 2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/
/*
学习cstdio里面 sscanf sprintf!!!!!!
这个思路非常棒！！！
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;
int main()
{
	int n, cnt = 0;
	char a[50] = "", b[50] = "";
	double temp, sum = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", a);/*重点之重点*/
		sscanf(a, "%lf", &temp);
		sprintf(b, "%.2lf", temp);
		int flag = 0;
		for (int j = 0; j < strlen(a); j++)
		{
			if (a[j] != b[j]) flag = 1;
		}
		if (flag || temp < -1000 || temp > 1000)
		{
			printf("ERROR: %s is not a legal number\n", a);
			continue;
		}
		else
		{
			sum += temp;
			cnt++;
		}
	}
	if (cnt == 1)
	{
		printf("The average of 1 number is %.2lf", sum);
	}
	else if (cnt > 1)
	{
		printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
	}
	else
	{
		printf("The average of 0 numbers is Undefined");
	}
	return 0;
}