/*
1012 The Best Rank£¨25 point(s)£©
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algrbra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (¡Ü2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output Specification:
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output N/A.

Sample Input:
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output:
1 C
1 M
1 E
1 A
3 A
N/A
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

char c[4] = { 'A','C','M','E' };
struct Student
{
	int  Score[4] = { 0 };
	int Rank[4] = { 1,1,1,1 };
	int ID = 0;
};
Student Stu[100000];

char state = 'A';
bool cmp(Student a, Student b)
{
	switch (state)
	{
	case 'A':
		return a.Score[0] > b.Score[0];
	case 'C':
		return a.Score[1] > b.Score[1];
	case 'M':
		return a.Score[2] > b.Score[2];
	case 'E':
		return a.Score[3] > b.Score[3];
	default:
		break;
	}
}
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> Stu[i].ID >> Stu[i].Score[1] >> Stu[i].Score[2] >> Stu[i].Score[3];
		Stu[i].Score[0] = (Stu[i].Score[1] + Stu[i].Score[2] + Stu[i].Score[3]);
	}
	for (int i = 0; i < 4; i++)
	{
		state = c[i];
		sort(&Stu[0], &Stu[n], cmp);
		for (int j = 0; j < n; j++)
		{
			if (Stu[j].Score[i] == Stu[j - 1].Score[i] && j > 0)
			{
				Stu[j].Rank[i] = Stu[j - 1].Rank[i];
			}
			else
			{
				Stu[j].Rank[i] = j + 1;
			}
		}
	}
	map <int, int>exist;
	for (int i = 0; i < n; i++)
	{
		exist[Stu[i].ID] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		if (exist.count(tmp) != 0)
		{
			Student s = Stu[exist[tmp]];
			int bestRank = 100000, bestIndex;
			for (int j = 0; j < 4; j++)
			{
				if (bestRank > s.Rank[j])
				{
					bestIndex = j;
					bestRank = s.Rank[j];
				}
			}
			printf("%d %c\n", s.Rank[bestIndex], c[bestIndex]);
		}
		else
		{
			printf("N/A\n");
		}
	}
	return 0;
}