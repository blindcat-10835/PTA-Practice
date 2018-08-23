/*
1015 �²��ۣ�25 point(s)��
�δ�ʷѧ��˾����ڡ�����ͨ��������һ�������ġ��²��ۡ������ǹʲŵ�ȫ��ν֮ʥ�ˣ��ŵ¼���ν֮���ˣ���ʤ��ν֮���ӣ���ʤ��ν֮С�ˡ���ȡ��֮����������ʥ�ˣ����Ӷ���֮�������С�ˣ����������ˡ���

�ָ���һ�������ĵ²ŷ����������˾�������۸���¼ȡ������

�����ʽ��
�����һ�и��� 3 �����������ֱ�Ϊ��N����10
5
����������������L����60����Ϊ¼ȡ��ͷ����ߣ����·ֺͲŷ־������� L �Ŀ��������ʸ񱻿���¼ȡ��H�� < 100����Ϊ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ������򣻲ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮�󣻵²ŷ־����� H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ����򣬵����ڵڶ��࿼��֮�������ﵽ����� L �Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮��

	��� N �У�ÿ�и���һλ��������Ϣ��������׼��֤�� �·� �ŷ֣�����׼��֤��Ϊ 8 λ�������²ŷ�Ϊ����[0, 100] �ڵ����������ּ��Կո�ָ���

	�����ʽ��
	�����һ�����ȸ����ﵽ��ͷ����ߵĿ������� M����� M �У�ÿ�а��������ʽ���һλ��������Ϣ��������������˵���Ĺ���Ӹߵ������򡣵�ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У����·�Ҳ���У���׼��֤�ŵ����������

	����������
	14 60 80
	10000001 64 90
	10000002 90 60
	10000011 85 80
	10000003 85 80
	10000004 80 85
	10000005 82 77
	10000006 83 76
	10000007 90 78
	10000008 75 79
	10000009 59 90
	10000010 88 45
	10000012 80 100
	10000013 90 99
	10000014 66 60
	���������
	12
	10000013 90 99
	10000012 80 100
	10000003 85 80
	10000011 85 80
	10000004 80 85
	10000007 90 78
	10000006 83 76
	10000005 82 77
	10000002 90 60
	10000014 66 60
	10000008 75 79
	10000001 64 90
	*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
struct Student
{
	int ID = 0, Morality = 0, Ability = 0;
	int rank = 4;
};

bool cmp(Student A, Student B)
{
	if (A.rank != B.rank)return A.rank < B.rank;
	else if (A.Morality + A.Ability != B.Morality + B.Ability)
	{
		return A.Morality + A.Ability > B.Morality + B.Ability;
	}
	else if (A.Morality != B.Morality)
	{
		return A.Morality > B.Morality;
	}
	else
	{
		return A.ID < B.ID;
	}
}
int main(int argc, char const *argv[])
{
	int N, L, H;
	Student *St = new Student[100000];
	cin >> N >> L >> H;
	int tempID, tempMorality, tempAbility;
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> tempID >> tempMorality >> tempAbility;
		if (tempAbility >= L && tempMorality >= L)
		{
			St[j].ID = tempID;
			St[j].Ability = tempAbility;
			St[j].Morality = tempMorality;
			if (tempAbility >= H && tempMorality >= H)
			{
				St[j].rank = 1;
			}
			else if (tempMorality >= H && tempAbility < H)
			{
				St[j].rank = 2;
			}
			else if (tempMorality >= tempAbility)
			{
				St[j].rank = 3;
			}
			else
			{
				St[j].rank = 4;
			}
			j++;
		}
	}

	sort(St, St + j, cmp);
	cout << j << endl;
	for (int i = 0; i < j; i++)
	{
		printf("%d %d %d\n", St[i].ID, St[i].Morality, St[i].Ability);
	}
	return 0;
}