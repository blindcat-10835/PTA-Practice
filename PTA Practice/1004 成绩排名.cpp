/*1004 �ɼ�����(20)��20 point(s)��
����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��ÿ�������������1��������������ʽΪ\

��1�У�������n
��2�У���1��ѧ�������� ѧ�� �ɼ�
��3�У���2��ѧ�������� ѧ�� �ɼ�
... ... ...
��n + 1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�

�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

����������

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������

Mike CS991301
Joe Math990112*/
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

int main(int argc, char const *argv[])
{
	int length = 0, score[MAX];
	string name[MAX], number[MAX];
	cin >> length;
	int i = length;
	while (i--)
	{
		cin >> name[i] >> number[i] >> score[i];
	}
	int max = 0, min = 101, m = 0, n = 0;
	i = length;
	while (i--)
	{
		if (score[i] > max)
		{
			max = score[i];
			m = i;
		}
		if (score[i] < min)
		{
			min = score[i];
			n = i;
		}
	}
	cout << name[m] << " " << number[m] << endl;
	cout << name[n] << " " << number[n] << endl;

	return 0;
}