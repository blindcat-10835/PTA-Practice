/*
7-47 ��ӡѡ��ѧ��������25 point(s)��
����ȫУ�����40000��ѧ�������2500�ſγ̡��ָ���ÿ��ѧ����ѡ���嵥��Ҫ�����ÿ�ſε�ѡ��ѧ��������

�����ʽ:
����ĵ�һ����������������N����40000����ΪȫУѧ��������K����2500����Ϊ�ܿγ������˺�N�У�ÿ�а���һ��ѧ��������3����дӢ����ĸ+1λ���֣���һ��������C����20�����������ѡ�Ŀγ������������C���γ̱�š���������γ̴�1��K��š�

�����ʽ:
˳������γ�1��K��ѡ��ѧ����������ʽΪ����ÿһ�ſΣ�������һ��������γ̱�ź�ѡ��ѧ��������֮���ÿո�ָ�����֮���ڵڶ��а��ֵ������ѧ��������ÿ��ѧ������ռһ�С�

��������:
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
�������:
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
*/
/*
blindcat
ע��c_str() ��ϸ��
	printf("%s\n", i->c_str());
	scanf("%s", Course.c_str());

���ʣ���������
Ϊʲô��char[] ���������sort���� !!
����string push ��ȥ�Ͳ������ˣ���������!!!
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
bool cmp(string s1, string s2)
{
	return s1 < s2;
}
int main(int argc, char const *argv[])
{
	int N = 40000, K = 2500;
	scanf("%d%d", &N, &K);
	map <int, vector<string> > CourseToStudent;
	for (int i = 0; i < N; i++)
	{
		int number;
		char Course[5];
		scanf("%s %d ", Course, &number);
		//string s;
		//scanf("%s %d ", s.c_str(), &number);
		while (number--)
		{
			int tmp;
			scanf("%d", &tmp);
			CourseToStudent[tmp].push_back(Course);
			//CourseToStudent[tmp].push_back(s);
		}
	}
	for (int i = 1; i <= K; i++)
	{
		vector<string> &c = CourseToStudent[i];
		sort(c.begin(), c.end());
		printf("%d %d\n", i, c.size());
		for (auto i = c.begin(); i != c.end(); i++)
		{
			/*ע��c_str() ��ϸ��*/
			printf("%s\n", i->c_str());
		}
	}
	return 0;
}