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

typedef int OutType;
typedef string InType;
class SolutionMy
{
public:
	int lengthOfLongestSubstring(string s)
	{
		if (s.size() == 1)return 1;
		if (s.size() == 0)return 0;
		int length = 1, begin = 0, end = 0, maxEnd = s.size() - 1;
		int tmpBegin = 0, tmpEnd = 0;
		for (tmpBegin = 0; tmpBegin < maxEnd; tmpBegin++)
		{
			tmpEnd = tmpBegin;
			bool t[256] = { false };
			while (tmpEnd <= maxEnd && !t[s[tmpEnd] - 0])
			{
				t[s[tmpEnd] - 0] = true;
				tmpEnd++;
			}
			if (tmpEnd - tmpBegin > length)
			{
				length = tmpEnd - tmpBegin;
				begin = tmpBegin;
				end = tmpEnd;
			}
			while (s[tmpBegin] != s[tmpEnd])
			{
				tmpBegin++;
			}
		}
		return length;
	}
};
static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int charMap[256] = { -1 };
		memset(charMap, -1, sizeof(charMap));
		int start = 0;
		int ans = 0;
		for (int rear = 0; rear < s.length(); rear++)
		{
			char rearChar = s[rear];
			if (charMap[rearChar] >= start)
			{
				start = charMap[rearChar] + 1;
			}
			else
			{
			}

			charMap[rearChar] = rear;
			int buf = rear - start + 1;
			//cout<<start<<" "<<rear<<" "<<buf<<endl;
			ans = ans < buf ? buf : ans;
		}
		return ans;
	}
};
int main(int argc, char const *argv[])
{
	InType S1 = "asdfdgshdfadfweazcdf";
	Solution Condition;
	OutType Result = Condition.lengthOfLongestSubstring(S1);
	cout << Result << endl;
	return 0;
}