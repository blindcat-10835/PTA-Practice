/*
1009 ˵���� (20)��20 point(s)��
����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������

�����ʽ�������������һ��������������һ���ڸ����ܳ��Ȳ�����80���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮����1���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�

�����ʽ��ÿ���������������ռһ�У���������ľ��ӡ�

����������

Hello World Here I Come
���������

Come I Here World Hello
*/
/*
pat 1009. ˵���� (20) - ��Ӱ - ����԰
https://www.cnblogs.com/qinduanyinghua/p/5494608.html
blindact:
�������ʮ�������������'\0'��
ʵ�����ǲ��ǿ�����stack��������£�ע�⵽����������
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	char c[41][81], tmp;
	int i = 0, j = 0;
	while ((tmp = getchar()) != '\n')
	{
		if (tmp == ' ')
		{
			c[i++][j] = '\0';
			j = 0;
		}
		else c[i][j++] = tmp;
	}
	c[i][j] = '\0';
	cout << c[i--];
	while (i >= 0)
	{
		cout << ' ' << c[i--];
	}
	return 0;
}