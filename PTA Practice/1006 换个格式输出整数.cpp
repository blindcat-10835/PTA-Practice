/*1006 ������ʽ������� (15)��15 point(s)��
����������ĸB����ʾ���١�����ĸS��ʾ��ʮ�����á�12...n������ʾ��λ����n��&lt10����������ʽ�������һ��������3λ��������������234Ӧ�ñ����ΪBBSSS1234����Ϊ����2�����١���3����ʮ�����Լ���λ��4��

�����ʽ��ÿ�������������1����������������������n��&lt1000����

�����ʽ��ÿ���������������ռһ�У��ù涨�ĸ�ʽ���n��

��������1��

234
�������1��

BBSSS1234
��������2��

23
�������2��

SS123
*/
#include <iostream>
#include <string>
#define MAX 102
using namespace std;

int main(int argc, char const *argv[])
{
	int b = 0, s = 0, g = 0;
	int number;
	cin >> number;
	b = number / 100;
	g = number % 10;
	s = number % 100 / 10;
	while (b--)
	{
		cout << "B";
	}
	while (s--)
	{
		cout << "S";
	}
	for (int i = 0; i < g; i++)
	{
		cout << i + 1;
	}
	return 0;
}