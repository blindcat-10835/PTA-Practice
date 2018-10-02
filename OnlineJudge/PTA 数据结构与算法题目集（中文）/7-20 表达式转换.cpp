/*
7-20 表达式转换 （25 point(s)）
算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。日常使用的算术表达式是采用中缀表示法，即二元运算符位于两个运算数中间。请设计程序将中缀表达式转换为后缀表达式。

输入格式:
输入在一行中给出不含空格的中缀表达式，可包含+、-、*、\以及左右括号()，表达式不超过20个字符。

输出格式:
在一行中输出转换后的后缀表达式，要求不同对象（运算数、运算符号）之间以空格分隔，但结尾不得有多余空格。

输入样例:
2+3*(7-4)+8/4
输出样例:
2 3 7 4 - * + 8 4 / +
*/
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
int Prio(char a)
{
	int ret = -1;
	switch (a)
	{
	default:
		break;
	case '+':
		ret = 1;
		break;
	case '-':
		ret = 1;
		break;
	case '*':
		ret = 2;
		break;
	case '/':
		ret = 2;
		break;
	case '(':
		ret = 0;
		break;
	}
	return ret;
}

bool Compare(char a, char b)
{
	return  Prio(a) > Prio(b);
}
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	if (s[0] == '-')
	{
		cout << '-';
		s.erase(0, 1);
	}
	else if (s[0] == '+')
	{
		s.erase(0, 1);
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-' && s[i - 1] == '-')
		{
			s.replace(i, 2, "+");
		}
		else if (s[i] == '-' && s[i - 1] == '+')
		{
			s.erase(i - 1, 1);
		}
		else if (s[i] == '+' && s[i - 1] == '+')
		{
			s.erase(i, 1);
		}
		else if (s[i] == '+' && s[i - 1] == '-')
		{
			s.erase(i, 1);
		}
	}
	vector<char> Stack;

	for (int i = 0; i < s.size(); i++)
	{
		if (isalnum(s[i]) || s[i] == '.')
		{
			cout << s[i];
		}
		else if (s[i] == '(')
		{
			Stack.push_back(s[i]);
			if (s[i + 1] == '-')
			{
				cout << '-'; i++;
			}
			else if (s[i + 1] == '+')
			{
				i++;
			}
		}
		else if (s[i] == ')')
		{
			while (!Stack.empty() && Stack.back() != '(')
			{
				cout << ' ' << Stack.back();
				Stack.pop_back();
			}
			Stack.pop_back();
		}
		else
		{
			while (!Stack.empty() && !Compare(s[i], Stack.back()))
			{
				cout << ' ' << Stack.back();
				Stack.pop_back();
			}
			Stack.push_back(s[i]);
			cout << ' ';
		}
	}
	while (!Stack.empty())
	{
		cout << ' ' << Stack.back();
		Stack.pop_back();
	}
	cout << endl;
	return 0;
}