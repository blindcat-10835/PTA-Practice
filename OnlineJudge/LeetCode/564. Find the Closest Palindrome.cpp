//没做出来(┬＿┬)
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
typedef string OutType;
typedef string InType;
class Solution_My
{
public:
	long long StringToInt(string n)
	{
		int i = n.size() - 1, e = 0;
		long long ret = 0;
		while (i != -1)
		{
			ret = ret + (n[i] - '0')*pow(10, e);
			e++;
			i--;
		}
		return ret;
	}

	long long toPalindromic(string n)
	{
		int i = 0, j = n.size() - 1;
		while (i < j)
		{
			n[j] = n[i];
			i++;
			j--;
		}
		return StringToInt(n);
	}

	string nearestPalindromic(string &n)
	{
		long long length = n.size(),
			makeLeft = (long)pow(10, length / 2);
		long long ansHigh = ((long)pow(10, length) + 1),//10001
			ansLow = ((long)pow(10, length - 1) - 1),//999
			ansSelf = StringToInt(n);//1234
		long long ansMinus = (ansSelf / makeLeft - 1)*makeLeft,//1100
			ansPlus = (ansSelf / makeLeft + 1)*makeLeft;//1300
		long long T[5] = { ansLow,toPalindromic(n),ansHigh,toPalindromic(to_string(ansMinus)),toPalindromic(to_string(ansPlus)) };
		sort(T, T + 5);
		long long min_i = 0, minabs = fabs(T[0] - ansSelf);
		for (int i = 1; i < 5; i++)
		{
			if (fabs(T[i] - ansSelf) < minabs&&T[i] != ansSelf)
			{
				min_i = i;
				minabs = fabs(T[i] - ansSelf);
			}
		}
		n = to_string(T[min_i]);
		return n;
	}
};

class Solution
{
public:
	string nearestPalindromic(string n)
	{
		int l = n.size();
		set<long> candidates;
		// biggest, one more digit, 10...01
		candidates.insert(long(pow(10, l)) + 1);
		// smallest, one less digit, 9...9 or 0
		candidates.insert(long(pow(10, l - 1)) - 1);
		// the closest must be in middle digit +1, 0, -1, then flip left to right
		long prefix = stol(n.substr(0, (l + 1) / 2));//学习一下string to long 函数
		for (int i = -1; i <= 1; i++)
		{
			string p = to_string(prefix + i);
			string pp = "";
			if (l % 2 == 0)	pp = p + string(p.rbegin(), p.rend());//学习一下字符串倒转！！
			else  pp = p + string(p.rbegin() + 1, p.rend());
			cout << "pp is " << pp << endl;
			candidates.insert(stol(pp));
		}
		candidates.erase(stol(n));
		long minGap = LONG_MAX;
		string minVar = "";

		for (auto num : candidates)
		{
			long gap = abs(num - stol(n));
			if (gap < minGap)
			{
				minGap = gap;
				minVar = to_string(num);
			}
		}
		return minVar;
	}
};
int main(int argc, char const *argv[])
{
	InType S = "807045053224792883";
	Solution Condition;
	OutType Result = Condition.nearestPalindromic(S);
	cout << Result << endl;
	return 0;
}