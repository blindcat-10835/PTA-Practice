/*
1067 �����루20 point(s)��
������ͼ��¼ĳ��ϵͳȴ��������ʱ��ϵͳһ��ֻ�������㳢�����޶�Σ��������������ʱ���˺žͻᱻ���������������ʵ�����С���ܡ�

�����ʽ��
�����ڵ�һ�и���һ�����루���Ȳ����� 20 �ġ��������ո�Tab���س��ķǿ��ַ�������һ�������� N���� 10�����ֱ�����ȷ�������ϵͳ�����ԵĴ��������ÿ�и���һ���Իس������ķǿ��ַ��������û�������������롣���뱣֤������һ�γ��ԡ�������һ��ֻ�е��� # �ַ�ʱ�����������������һ�в����û������롣

�����ʽ��
���û���ÿ�����룬�������ȷ�������ҳ��Դ��������� N������һ������� Welcome in����������������Ǵ���ģ�����һ���а���ʽ��� Wrong password: �û�����Ĵ������룻�������Դﵽ N ��ʱ�������һ�� Account locked������������

�������� 1��
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#
������� 1��
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked
�������� 2��
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#
������� 2��
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in
*/
/*
blindacat:
��һ���Ҫ���ǣ�
1. �����м��пո�ʹ��getline();
2. ʹ��getchar()�Ե��س�

*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	string s, temp;
	int N;

	cin >> s >> N;
	getchar();//ע��Ҫ�Ե��س�
	while (N--)
	{
		getline(cin, temp);
		if (temp == "#")return 0;
		else if (temp == s)
		{
			cout << "Welcome in" << endl;
			return 0;
		}
		else
		{
			cout << "Wrong password: " << temp << endl;
		}
	}
	cout << "Account locked" << endl;

	return 0;
}