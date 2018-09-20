/*
7-37 模拟EXCEL排序 （25 point(s)）
Excel可以对一组纪录按任意指定列排序。现请编写程序实现类似功能。

输入格式:
输入的第一行包含两个正整数N(≤10
​5
​​ ) 和C，其中N是纪录的条数，C是指定排序的列号。之后有 N行，每行包含一条学生纪录。每条学生纪录由学号（6位数字，保证没有重复的学号）、姓名（不超过8位且不包含空格的字符串）、成绩（[0, 100]内的整数）组成，相邻属性用1个空格隔开。

输出格式:
在N行中输出按要求排序后的结果，即：当C=1时，按学号递增排序；当C=2时，按姓名的非递减字典序排序；当C=3时，按成绩的非递减排序。当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。

输入样例:
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
输出样例:
000001 Zoe 60
000007 James 85
000010 Amy 90
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
struct Student
{
	int ID = 0, Score = 0;
	string Name = "";
};
bool cmp_Name(Student A, Student B)
{
	if (A.Name != B.Name)
	{
		return A.Name < B.Name;
	}
	else
	{
		return A.ID < B.ID;
	}
}
bool cmp_ID(Student A, Student B)
{
	return A.ID < B.ID;
}
bool cmp_Score(Student A, Student B)
{
	if (A.Score != B.Score)
	{
		return A.Score < B.Score;
	}
	else
	{
		return A.ID < B.ID;
	}
}
int main(int argc, char const *argv[])
{
	int N = 100000, C;
	scanf("%d %d\n", &N, &C);
	vector<Student> Stu(N);
	for (int i = 0; i < N; i++)
	{
		cin >> Stu[i].ID >> Stu[i].Name >> Stu[i].Score;
	}
	switch (C)
	{
	default:
		break;
	case 1:
		sort(Stu.begin(), Stu.end(), cmp_ID);
		break;
	case 2:
		sort(Stu.begin(), Stu.end(), cmp_Name);
		break;
	case 3:
		sort(Stu.begin(), Stu.end(), cmp_Score);
		break;
	}
	for (auto iter : Stu)
	{
		printf("%06d %s %d\n", iter.ID, iter.Name.c_str(), iter.Score);
	}
	return 0;
}