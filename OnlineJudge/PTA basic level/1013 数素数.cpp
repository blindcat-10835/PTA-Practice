/*
1013 数素数 (20)（20 point(s)）
令P~i~表示第i个素数。现任给两个正整数M <= N <= 10^4^，
请输出P~M~到P~N~的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从P~M~到P~N~的所有素数，每10个数字占1行，
其间以空格分隔，但行末不得有多余空格。

输入样例：

5 27
输出样例：

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