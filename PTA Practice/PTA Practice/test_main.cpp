#include <algorithm> //for using "sort"
#include <iostream>
#include <string>
#include <cmath>
#include <map>//for using "map"
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

	sort(Un, Un + j, cmp);

	int i_rank = 1;
	cout << j << endl;
	for (int i = 0; i < j; i++)
	{
		if (i&&int(Un[i].total_score) != int(Un[i - 1].total_score))i_rank = i + 1;

		cout << i_rank << ' ' << Un[i].name << ' ' << int(Un[i].total_score) << ' ' << Un[i].number_of_students << endl;
	}
	return 0;
}