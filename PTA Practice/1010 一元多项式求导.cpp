/*
1010 һԪ����ʽ�� (25)��25 point(s)��
��ƺ�����һԪ����ʽ�ĵ�������ע��x^n^��nΪ��������һ�׵���Ϊn*x^n-1^����

�����ʽ����ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���

�����ʽ������������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�ע�⡰�����ʽ����ָ����ϵ������0�����Ǳ�ʾΪ��0 0����

����������

3 4 -5 2 6 1 -2 0
���������

12 3 -10 1 6 0
*/

/*
PAT_1010 һԪ����ʽ�� - ����SAMA�ĸ�Ц�ճ� - ����԰
https://www.cnblogs.com/xzt6/p/5759181.html
���Բο�һ��scanf ��EOF��ʹ��
EOF�ĺ�����scanf�ķ���ֵ - CSDN����
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