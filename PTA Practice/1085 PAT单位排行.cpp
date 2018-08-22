/*
1085 PAT��λ���У�25 point(s)��
ÿ�� PAT ���Խ����󣬿������Ķ��ᷢ��һ��������λ���а񡣱��������ʵ��������ܡ�

�����ʽ��
�����һ�и���һ�������� N����10
5
������������������� N �У�ÿ�а����и�ʽ����һ����������Ϣ��

׼��֤�� �÷� ѧУ
����׼��֤������ 6 ���ַ���ɵ��ַ�����������ĸ��ʾ���Եļ���B�����Ҽ���A����׼���T���������÷���[0, 100] �����ڵ�������ѧУ���ɲ����� 6 ��Ӣ����ĸ��ɵĵ�λ�루��Сд�޹أ���ע�⣺��Ŀ��֤ÿ��������׼��֤���ǲ�ͬ�ġ�

�����ʽ��
������һ���������λ������������¸�ʽ�ǽ��������λ�����а�

���� ѧУ ��Ȩ�ܷ� ��������
���������Ǹõ�λ���������� 1 ��ʼ����ѧУ��ȫ����Сд��ĸ����ĵ�λ�룻��Ȩ�ֶܷ���Ϊ�Ҽ��ܷ� / 1.5 + �׼��ܷ� + �����ܷ� * 1.5���������֣����������Ǹ����ڵ�λ�Ŀ�������������

ѧУ���Ȱ���Ȩ�ܷ����С����в��У���Ӧ��Ӧ��ͬ����������������������������������Ȼ���У��򰴵�λ����ֵ��������

����������
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
���������
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;
struct Student
{
	int score;
	string school;
	string ID;
};
struct University
{
	string name = "";
	int  number_of_students = 0;
	float total_score = 0;
};
bool cmp(University A, University B)
{
	if ((int)A.total_score != (int)B.total_score) return (int)A.total_score > (int)B.total_score;//������ͬ��˭��˭��ǰ
	else if (A.number_of_students != B.number_of_students) return A.number_of_students < B.number_of_students;       //������ͬ��ѧ������ͬ��ѧ����С����ǰ
	else return A.name < B.name;          //����ֻ�����ֵ����ˣ�˭С˭���ֵ�����ǰ
}
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	Student St;
	University *Un = new University[100000];
	int u = 0;
	map<string, int> SchoolIndex;
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> St.ID >> St.score >> St.school;
		//		���£�����ѧУ�ַ���תСд
		for (int j = 0; j < St.school.length(); j++)
		{
			if (St.school[j] >= 'A'&&St.school[j] <= 'Z')
			{
				St.school[j] = St.school[j] - 'A' + 'a';
			}
		}

		/*���school�ļ���һ�γ��֣���Ӧ�洢�ڴ��㿪ʼ��������*/
		if (SchoolIndex.count(St.school) == 0)
		{
			SchoolIndex[St.school] = j++;
			Un[SchoolIndex[St.school]].name = St.school;
		}

		Un[SchoolIndex[St.school]].number_of_students++;

		//���£�����ѧ������ת��
		if (St.ID[0] == 'T')
		{
			Un[SchoolIndex[St.school]].total_score += (St.score * 1.5);
		}
		else if (St.ID[0] == 'B')
		{
			Un[SchoolIndex[St.school]].total_score += (St.score / 1.5);
		}
		else
		{
			Un[SchoolIndex[St.school]].total_score += St.score;
		}
	}
	//calculate rank
	/*u = 0;
	for (u = 0; Un[u].name != ""; u++)
	{
	}*/
	sort(Un, Un + u, cmp);

	//University max;
	//int i_max = -1;
	//int i_rank = 1;
	//for (int j = 0; j < u; j++)
	//{
	//	max.name = "";
	//	max.number_of_students = 0;
	//	max.total_score = -1;
	//	for (int i = j; i < u; i++)
	//	{
	//		if (max.total_score < Un[i].total_score)
	//		{
	//			max = Un[i];
	//			i_max = i;
	//		}
	//		else if (max.total_score == Un[i].total_score)
	//		{
	//			if (max.number_of_students > Un[i].number_of_students)
	//			{
	//				max = Un[i];
	//				i_max = i;
	//			}
	//			else if (max.number_of_students == Un[i].number_of_students)
	//			{
	//				if (max.name > Un[i].name)
	//				{
	//					max = Un[i];
	//					i_max = i;
	//				}
	//			}
	//		}
	//	}
	//	Un[i_max] = Un[j];
	//	Un[j] = max;
	//	if (j&&int(Un[j].total_score) != int(Un[j - 1].total_score))i_rank = j + 1;
	//	Un[j].rank = i_rank;
	//}
	int i_rank = 1;
	cout << u << endl;
	for (int i = 0; i < u; i++)
	{
		if (i&&int(Un[i].total_score) != int(Un[i - 1].total_score))i_rank = i + 1;

		cout << i_rank << ' ' << Un[i].name << ' ' << int(Un[i].total_score) << ' ' << Un[i].number_of_students << endl;
	}
	return 0;
}