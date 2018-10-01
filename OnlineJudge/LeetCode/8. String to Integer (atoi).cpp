/*8. String to Integer (atoi)*/

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef int OutType;
typedef string InType;
class Solution
{
public:
	int myAtoi(string str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (!isblank(str[i]))
			{
				str.erase(0, i);
				break;
			}
		}
		string ret = "";
		bool isSigned = false, isEmpty = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (isdigit(str[i]))
			{
				ret = ret + str[i];
				isSigned = true;
				isEmpty = false;
			}
			else if ((str[i] == '-' || str[i] == '+') && !isSigned)
			{
				ret = ret + str[i];
				isSigned = true;
			}
			else
			{
				break;
			}
		}
		if (isEmpty)return 0;
		long long t = 0;
		sscanf(ret.c_str(), "%lld", &t);
		if (t > INT_MAX)t = INT_MAX;
		else if (t < INT_MIN)t = INT_MIN;
		return (int)t;
	}
};
int main(int argc, char const *argv[])
{
	InType S = "  -91283472332";
	Solution Condition;
	OutType Result = Condition.myAtoi(S);
	cout << Result << endl;
	return 0;
}