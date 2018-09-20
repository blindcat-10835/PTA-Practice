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