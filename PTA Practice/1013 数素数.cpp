/*
1013 ������ (20)��20 point(s)��
��P~i~��ʾ��i�����������θ�����������M <= N <= 10^4^��
�����P~M~��P~N~������������

�����ʽ��

������һ���и���M��N������Կո�ָ���

�����ʽ��

�����P~M~��P~N~������������ÿ10������ռ1�У�
����Կո�ָ�������ĩ�����ж���ո�

����������

5 27
���������

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isPrime(int i);
int main(int argc, char const *argv[])
{
	int Prime[10001] = { -1 };
	int m, n;
	cin >> m >> n;
	int i = 2, k = 1;
	for (k = 1; k <= n;)
	{
		if (isPrime(i))
		{
			Prime[k++] = i;
		}
		i++;
	}
	k = 0, i = 0;
	for (k = m; k < n; k++)
	{
		printf("%d", Prime[k]);
		if ((++i) % 10 != 0)cout << ' ';
		else cout << endl;
	}
	printf("%d", Prime[k]);
	return 0;
}
bool isPrime(int i)
{
	for (int j = 2; j <= sqrt(i); j++)
	{
		if (i%j == 0)return false;
	}
	return true;
}