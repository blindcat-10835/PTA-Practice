/*
1010 Radix£¨25 point(s)£©
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true ? The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N
1
and N
2
, your task is to find the radix of one number while that of the other is given.

Input Specification :
Each input file contains one test case.Each case occupies a line which contains 4 positive integers :

N1 N2 tag radix

Here N1 and N2 each has no more than 10 digits.A digit is less than its radix and is chosen from the set{ 0 - 9, a - z } where 0 - 9 represent the decimal numbers 0 - 9, and a - z represent the decimal numbers 10 - 35. The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.

Output Specification :
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true.If the equation is impossible, print Impossible.If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1 :
2
Sample Input 2 :
1 ab 1 2
Sample Output 2 :
Impossible
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

long long Str_to_Int(string N, long long  radix)
{
	long long ret = 0;
	long long E = 1;
	for (int i = N.length() - 1; i >= 0; i--)
	{
		if (isdigit(N[i]))
		{
			ret = ret + int(N[i] - '0')*E;
			E = E * radix;
		}
		else if (islower(N[i]))
		{
			ret = ret + int(N[i] - 'a' + 10)*E;
			E = E * radix;
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	int tag, radix;
	string N1, N2;
	cin >> N1 >> N2 >> tag >> radix;
	if (tag == 2)
	{
		string t = N1;
		N1 = N2;
		N2 = t;
	}
	long long  a = Str_to_Int(N1, radix);

	long long Low = 0;/*big point!!!!*/
	int tmp = 0;
	for (int i = 0; i < N2.length(); i++)
	{
		if (isdigit(N2[i]))
		{
			tmp = int(N2[i] - '0');
		}
		else
		{
			tmp = int(N2[i] - 'a' + 10);
		}
		if (Low < tmp)
		{
			Low = tmp;
		}
	}
	Low += 1;

	long long High = a + 1;
	if (High < Low)High = Low;

	long long  mid;
	while (Low <= High)
	{
		mid = (Low + High) / 2;
		long long  b = Str_to_Int(N2, mid);
		if (a == b)
		{
			cout << mid << endl;
			return 0;
		}
		else if (b > a || b < 0)/*big point !!!*/
		{
			High = mid - 1;
		}
		else
		{
			Low = mid + 1;
		}
	}
	cout << "Impossible\n";
	return 0;
}