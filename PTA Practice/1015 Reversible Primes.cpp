/*
1015 Reversible Primes£¨20 point(s)£©
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10
?5
?? ) and D (1<D¡Ü10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int  Reverse(string a, int radix)
{
	int ret = 0, e = 1;
	for (int i = 0; i < a.length(); i++)
	{
		ret += (int(a[i] - '0')*e);
		e *= radix;
	}
	return ret;
}
string  trans(int a, int radix)
{
	string ret = "";
	int b;
	while (a != 0)
	{
		b = a % radix;
		ret = to_string(b) + ret;
		a = a / radix;
	}
	return ret;
}
bool isPrime(int a)
{
	if (a > 3)
	{
		for (int i = 2; i <= sqrt(a); i++)
		{
			if (a%i == 0)return false;
		}
		return true;
	}
	else
	{
		return (a == 2 || a == 3);
	}
}
int main(int argc, char const *argv[])
{
	int a, b, tmp;
	string t = "";
	while (true)
	{
		cin >> a;
		if (a < 0)return 0;
		cin >> b;
		t = trans(a, b);
		tmp = Reverse(t, b);

		if (isPrime(a) && isPrime(tmp))printf("Yes\n");
		else  printf("No\n");
	}
	return 0;
}