#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef string OutType;
typedef string InType;
class Solution
{
public:
	void Inseart(string &s)
	{
		for (int i = 0; i < s.size() - 1; i += 2)
		{
			s.insert(i + 1, 1, '#');
		}
		s.push_back('#'); s.insert(0, 1, '#');
		return;
	}
	int maxS(int i, string &s)
	{
		int ret = 1;
		int f = i - 1, b = i + 1;
		while (f >= 0 && s[f] == s[b])
		{
			f--; b++;
			ret += 2;
		}
		return ret;
	}
	string longestPalindrome(string &s)
	{
		if (s.empty())return"";
		Inseart(s);
		int maxLen = 3, max_i = 1;
		for (int i = s.size() - 1; i > 0; i--)
		{
			int tmp = maxS(i, s);
			if (tmp > maxLen) { maxLen = tmp; max_i = i; }
		}
		string ret = s.substr(max_i - (maxLen - 1) / 2, maxLen);
		ret.erase(remove(ret.begin(), ret.end(), '#'), ret.end());
		return ret;
	}
};
int main(int argc, char const *argv[])
{
	InType S1 = "ac";
	Solution Condition;
	OutType Result = Condition.longestPalindrome(S1);
	cout << Result << endl;
	return 0;
}