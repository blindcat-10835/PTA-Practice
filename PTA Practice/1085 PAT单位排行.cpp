/*
1085 PAT单位排行（25 point(s)）
每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

输入格式：
输入第一行给出一个正整数 N（≤10
5
），即考生人数。随后 N 行，每行按下列格式给出一个考生的信息：

准考证号 得分 学校
其中准考证号是由 6 个字符组成的字符串，其首字母表示考试的级别：B代表乙级，A代表甲级，T代表顶级；得分是[0, 100] 区间内的整数；学校是由不超过 6 个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

输出格式：
首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：

排名 学校 加权总分 考生人数
其中排名是该单位的排名（从 1 开始）；学校是全部按小写字母输出的单位码；加权总分定义为乙级总分 / 1.5 + 甲级总分 + 顶级总分 * 1.5的整数部分；考生人数是该属于单位的考生的总人数。

学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。

输入样例：
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
输出样例：
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
	if ((int)A.total_score != (int)B.total_score) return (int)A.total_score > (int)B.total_score;//分数不同，谁大谁在前
	else if (A.number_of_students != B.number_of_students) return A.number_of_students < B.number_of_students;       //分数相同，学生数不同，学生数小的在前
	else return A.name < B.name;          //否则只能用字典序了，谁小谁的字典序在前
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
		//		以下，处理学校字符串转小写
		for (int j = 0; j < St.school.length(); j++)
		{
			if (St.school[j] >= 'A'&&St.school[j] <= 'Z')
			{
				St.school[j] = St.school[j] - 'A' + 'a';
			}
		}

		/*如果school的键第一次出现，对应存储在从零开始的数组里*/
		if (SchoolIndex.count(St.school) == 0)
		{
			SchoolIndex[St.school] = j++;
			Un[SchoolIndex[St.school]].name = St.school;
		}

		Un[SchoolIndex[St.school]].number_of_students++;

		//以下，处理学生分数转换
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