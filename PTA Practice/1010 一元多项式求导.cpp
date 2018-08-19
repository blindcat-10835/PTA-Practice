/*
1010 一元多项式求导 (25)（25 point(s)）
设计函数求一元多项式的导数。（注：x^n^（n为整数）的一阶导数为n*x^n-1^。）

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

输入样例：

3 4 -5 2 6 1 -2 0
输出样例：

12 3 -10 1 6 0
*/

/*
PAT_1010 一元多项式求导 - 宝宝SAMA的搞笑日常 - 博客园
https://www.cnblogs.com/xzt6/p/5759181.html
可以参考一下scanf 和EOF的使用
EOF的含义与scanf的返回值 - CSDN博客
https://blog.csdn.net/trochiluses/article/details/17655861

#include <cstdio>
int main()
{
	int m, n;
	int flag = 1;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (n > 0)
		{
			if (flag == 1)
			{
				printf("%d %d", m*n, n - 1);
				flag = 0;
			}
			else
			{
				printf(" %d %d", m*n, n - 1);
			}
		}
	}
	if (flag == 1)
		printf("0 0");

	return 0;
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	bool f = false;
	for (int c, e; scanf("%d%d", &c, &e) == 2; )
	{
		if (c*e != 0)
		{
			printf(f ? " %d %d" : "%d %d", c*e, e - 1);
			f = true;
		}
	}
	if (!f)
		puts("0 0");
	return 0;
}