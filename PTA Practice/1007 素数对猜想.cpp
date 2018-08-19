/*1007 素数对猜想（20 point(s)）
让我们定义d
​n
​​ 为：d
​n
​​ =p
​n+1
​​ −p
​n
​​ ，其中p
​i
​​ 是第i个素数。显然有d
​1
​​ =1，且对于n>1有d
​n
​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10
​5
​​ )，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isPrime(int j)
{
	for (int i = 2; i <= sqrt(j); i++)
	{
		if (j%i == 0)return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int last = 0;
	int count = 0;
	for (int i = 3; i <= N; i++)
	{
		if (isPrime(i))
		{
			if ((i - last) == 2)count++;
			last = i;
		}
	}
	cout << count;
	return 0;
}