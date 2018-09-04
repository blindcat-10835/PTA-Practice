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

	long long Low = 1;/*big point!!!!*/
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
			//printf("%lld\n", i);
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