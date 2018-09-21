/*
7-20 ���ʽת�� ��25 point(s)��
�������ʽ��ǰ׺��ʾ������׺��ʾ���ͺ�׺��ʾ������ʽ���ճ�ʹ�õ��������ʽ�ǲ�����׺��ʾ��������Ԫ�����λ�������������м䡣����Ƴ�����׺���ʽת��Ϊ��׺���ʽ��

�����ʽ:
������һ���и��������ո����׺���ʽ���ɰ���+��-��*��\�Լ���������()�����ʽ������20���ַ���

�����ʽ:
��һ�������ת����ĺ�׺���ʽ��Ҫ��ͬ������������������ţ�֮���Կո�ָ�������β�����ж���ո�

��������:
2+3*(7-4)+8/4
�������:
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