/*
7-49 ��ӡѧ��ѡ���嵥��25 point(s)��
����ȫУ�����40000��ѧ�������2500�ſγ̡��ָ���ÿ�ſε�ѡ��ѧ��������Ҫ�����ÿ��ǰ����ѯ��ѧ����ѡ���嵥��

�����ʽ:
����ĵ�һ����������������N����40000����Ϊǰ����ѯ�α��ѧ��������K����2500����Ϊ�ܿγ������˺�˳������γ�1��K��ѡ��ѧ����������ʽΪ����ÿһ�ſΣ�������һ��������γ̱�ţ���������γ̴�1��K��ţ���ѡ��ѧ��������֮���ÿո�ָ�����֮���ڵڶ��и���ѧ����������������ѧ��������1���ո�ָ���ѧ��������3����дӢ����ĸ+1λ������ɡ�ѡ����Ϣ֮����һ���ڸ�����N��ǰ����ѯ�α��ѧ�������֣���������ѧ��������1���ո�ָ���

�����ʽ:
��ÿλǰ����ѯ�α��ѧ����������������֣������ͬһ�������һ��������C�����������ѡ�Ŀγ���������󰴵���˳�����C���γ̵ı�š�����������1���ո�ָ���ע����ĩ�����������ո�

��������:
10 5
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6
�������:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
*/

/*
blindcat:
char s[5] ��stirng s ��һ���ģ�������֮����
5��ʾ��4���ַ������һ����'\0';
���������ص��ǵ�ַ��Ҫ�á�*��ȡֵʹ��
sort �������begin end��ʹ�ã�

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
int main(int argc, char const *argv[])
{
	int N = 40000, K = 2500;
	scanf("%d%d", &N, &K);
	map <string, vector<int> > StudentToCourse_i;
	for (int i = 0; i < K; i++)
	{
		int ID, number;
		scanf("%d %d", &ID, &number);
		while (number--)
		{
			char stu[5];
			cin >> stu;
			int k = -1;
			StudentToCourse_i[stu].push_back(ID);
		}
	}
	while (N--)
	{
		char stu[5];
		scanf("%s", &stu[0]);
		vector<int> &c = StudentToCourse_i[stu];
		sort(c.begin(), c.end());
		printf("%s %d", stu, c.size());
		for (auto i = c.begin(); i != c.end(); i++)
		{
			printf(" %d", *i);
		}
		printf("\n");
	}
	return 0;
}