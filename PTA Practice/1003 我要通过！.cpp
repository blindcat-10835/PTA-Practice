/*1003 ��Ҫͨ����(20)��20 point(s)��
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���\

�������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����\
��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�

�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (&lt10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��

����������

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������

YES
YES
YES
YES
NO
NO
NO
NO*/
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int n = 0, p = 0, a = 0, b = 0, c = 0, t = 0;
	bool isYES = true;
	cin >> n;
	string s;
	while (n--)
	{
		cin >> s;
		a = 0, p = 0, b = 0, t = 0, c = 0;
		for (int j = 0; j < s.length(); j++)
		{
			/*notice!!!!!!!
			 if string('P') replaced by string("P").there would be error;
			 why??????????
			*/
			if (s[j] == 'A')
			{
				if (p == 0)
				{
					a++;
				}
				else if (p == 1 && t == 0)
				{
					b++;
				}
				else if (p == 1 && t == 1)
				{
					c++;
				}
			}
			else if (s[j] == 'P'&&p == 0)
			{
				p++;
			}
			else if (s[j] == 'T'&&t == 0 && p == 1 && b >= 1)
			{
				t++;
			}
			else
			{
				isYES = false;
				break;
			}
		}
		if (p == 1 && c == a * b && t == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}