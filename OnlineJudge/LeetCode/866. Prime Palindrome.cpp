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
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
typedef int OutType;
typedef int InType;

class Solution
{
public:

	bool isPrime(int N)
	{
		if (N == 1)return false;
		for (int i = 2; i <= sqrt(N); i++)
		{
			if (N%i == 0)return false;
		}
		return true;
	}
	bool isPalidrome(int N)
	{
		string s = to_string(N);
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			if (s[i] != s[j])return false;
		}
		return true;
	}
	int findNextPalidrome(int N)
	{
		string s = to_string(N);
		//调整为回文；
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			s[j] = s[i];
		}
		if (stoi(s) > N)return stoi(s);

		//找到下一个
		int i = (s.size() + 1) / 2;
		int j = s.size() - i;
		string tmp = to_string(stoi(s.substr(0, i)) + 1);
		s = tmp + s.substr(i, j);

		//调整为回文；
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			s[j] = s[i];
		}
		return stoi(s);
	}
	int primePalindrome(int N)
	{
		if (!isPalidrome(N))N = findNextPalidrome(N);
		while (!isPrime(N))
		{
			N = findNextPalidrome(N);
		}
		return N;
	}
};

int main(int argc, char const *argv[])
{
	InType S1 = 11;
	Solution Condition;
	OutType Result = Condition.primePalindrome(S1);
	cout << Result << endl;
	return 0;
}