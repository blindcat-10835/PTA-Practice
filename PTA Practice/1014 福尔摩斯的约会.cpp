/*
1014 ����Ħ˹��Լ�� (20)��20 point(s)��
����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm��������̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��

������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�����ʽ��

��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣

����������

3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
���������

THU 14:04
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	string a, b, c, d;
	string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int i = 0, j = 0;
	cin >> a >> b >> c >> d;
	for (i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i] && j == 0 && a[i] >= 'A'&&a[i] <= 'G')
		{
			cout << week[a[i] - 'A'] << ' ';
			j = 1;
		}
		else if (j == 1 && a[i] == b[i])
		{
			if (a[i] >= '0'&&a[i] <= '9')
			{
				cout << '0' << a[i] - '0'; break;
			}
			else if (a[i] >= 'A'&&a[i] <= 'N')
			{
				cout << a[i] - 'A' + 10;
				break;
			}
		}
	}
	for (i = 0; i < c.length(); i++)
	{
		if (c[i] == d[i] && ((c[i] <= 'Z'&&c[i] >= 'A') || (c[i] <= 'z'&&c[i] >= 'a')))
		{
			if (i <= 9)
			{
				cout << ":0" << i << endl;; break;
			}
			else if (i)
			{
				cout << ':' << i << endl;
				break;
			}
		}
	}
	return 0;
}