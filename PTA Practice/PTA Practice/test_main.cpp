#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string s, a1, a2, result = "";
	cin >> s >> a1 >> a2;
	while (a1.length() < s.length())
	{
		a1 = "0" + a1;
	}
	while (a2.length() < s.length())
	{
		a2 = "0" + a2;
	}
	while (s.length() < a1.length())
	{
		s = "0" + s;
	}
	int carry = 0, last_carry = 0;
	int tmp = 0;
	for (int i = a1.length() - 1; i >= 0; i--)
	{
		tmp = a1[i] + a2[i] - 2 * '0' + last_carry;
		if (s[i] != '0')
		{
			if (tmp >= s[i] - '0')
			{
				tmp -= (s[i] - '0'); carry = 1;
			}
		}
		else
		{
			if (tmp >= 10)
			{
				tmp -= 10; carry = 1;
			}
		}
		result = char(tmp + '0') + result;
		last_carry = carry;
		carry = 0;
		tmp = 0;
	}
	result = char(last_carry + '0') + result;
	while (result[0] == '0')result.erase(0, 1);
	if (result == "")result = "0";
	cout << result << endl;
	return 0;
}