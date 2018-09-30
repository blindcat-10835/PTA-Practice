/*10. Regular Expression Matching
https://leetcode.com/problems/regular-expression-matching/description/
*/
//�ο��˴𰸵ĵݹ��㷨���Լ�û������
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
class Solution
{
public:
	bool isMatch(string s, string p)
	{
		if (p.empty())return s.empty();
		if (p[1] == '*')
		{
			return (isMatch(s, p.substr(2)))
				|| (!s.empty()
					&& (s[0] == p[0] || p[0] == '.')
					&& isMatch(s.substr(1), p)
					);
		}
		else
		{
			return true
				&& !s.empty()//ע�����еġ���s.empty()�����������substr���棻
				&& (s[0] == p[0] || p[0] == '.')
				&& isMatch(s.substr(1), p.substr(1));
		}
	}
};
int main(int argc, char const *argv[])
{
	string S = "a";
	string P = ".*..a*";
	Solution t;
	bool Is = t.isMatch(S, P);
	cout << Is << endl;

	return 0;
}