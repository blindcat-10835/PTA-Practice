/*
1081 ������루15 point(s)��
����Ҫ�������ĳ��վ���û�ע��ģ��дһ������Ϸ��Լ���С���ܡ�����վҪ���û����õ���������ɲ�����6���ַ���ɣ�����ֻ����Ӣ����ĸ�����ֺ�С���� .�������������ĸҲ�����֡�

�����ʽ��
�����һ�и���һ�������� N���� 100������� N �У�ÿ�и���һ���û����õ����룬Ϊ������ 80 ���ַ��ķǿ��ַ������Իس�������

�����ʽ��
��ÿ���û������룬��һ�������ϵͳ������Ϣ��������5�֣�

�������Ϸ������Your password is wan mei.��
�������̫�̣����ۺϷ���񣬶����Your password is tai duan le.��
������볤�ȺϷ��������ڲ��Ϸ��ַ��������Your password is tai luan le.��
������볤�ȺϷ�����ֻ����ĸû�����֣������Your password needs shu zi.��
������볤�ȺϷ�����ֻ������û����ĸ�������Your password needs zi mu.��
����������
5
123s
zheshi.wodepw
1234.5678
WanMei23333
pass*word.6
���������
Your password is tai duan le.
Your password needs shu zi.
Your password needs zi mu.
Your password is wan mei.
Your password is tai luan le.*/
/*

*/
#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	getchar();//Ϊ�˳Ե�س�����ʹ��getline֮ǰ�ǵ�
	while (N--)
	{
		string s = "";
		getline(cin, s);
		bool hasDigit = false, hasAlpha = false, isLegal = true;
		if (s.size() < 6)
		{
			cout << "Your password is tai duan le." << endl;
		}
		else
		{
			for (int i = 0; i < s.length(); i++)
			{
				if (isalpha(s[i]))
				{
					hasAlpha = true;
				}
				else if (isdigit(s[i]))
				{
					hasDigit = true;
				}
				else if (s[i] != '.')
				{
					isLegal = false;
				}
			}
			if (!isLegal)
			{
				printf("Your password is tai luan le.\n");
			}
			else if (!hasAlpha)
			{
				printf("Your password needs zi mu.\n");
			}
			else if (!hasDigit)
			{
				printf("Your password needs shu zi.\n");
			}
			else
			{
				printf("Your password is wan mei.\n");
			}
		}
	}
	return 0;
}