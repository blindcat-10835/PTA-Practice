/*
1011 A+B��C (15)��15 point(s)��
��������[-2^31^, 2^31^]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C��

�����ʽ��

�����1�и���������T(<=10)���ǲ��������ĸ�����������T�����������ÿ��ռһ�У�˳�����A��B��C���������Կո�ָ���

�����ʽ��

��ÿ�������������һ���������Case #X: true�����A+B>C�����������Case #X: false��������X�ǲ��������ı�ţ���1��ʼ����

����������

4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
���������

Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/
/*
����ע��int ��long ��long long ��float���������ͣ���
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int i, j = 1;
	cin >> i;
	long long a, b, c;
	while (i--)
	{
		cin >> a >> b >> c;
		if ((a + b - c > 0))
		{
			printf("Case #%d: true\n", j++);
		}
		else
		{
			printf("Case #%d: false\n", j++);
		}
	}
	return 0;
}