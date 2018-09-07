//1017	Queueing at Bank	25	710	2809	0.25
//1018	Public Bike Management	30	920	3695	0.25
//1021	Deepest Root	25	1059	3908	0.27
//1025	PAT Ranking	25	1444	5228	0.28
//1026	Table Tennis	30	372	2210	0.17

//1028	List Sorting	25	1020	3553	0.29

//1032	Sharing	25	1044	3701	0.28
//1033	To Fill or Not to Fill	25	758	2582	0.29
//1039	Course List for Student	25	1021	4350	0.23
//1047	Student List for Course	25	673	4191	0.16
//1052	Linked List Sorting	25	910	4184	0.22
//1055	The World's Richest	25	734	5904	0.12
//1057	Stack	30	637	2199	0.29

//1060	Are They Equal	25	793	3466	0.23
//1061	Dating	20	754	3394	0.22
//1065	Score[0] + B and Score[1](64bit)	20	1225	4770	0.26
//1067	Sort with Swap(0, i)	25	819	2931	0.28
//1068	Find More Coins	30	492	1749	0.28
//1072	Gas Station	30	690	2885	0.24
//1074	Reversing Linked List	25	747	2569	0.29
//1075	PAT Judge	25	697	3489	0.20
//1077	Kuchiguse	20	873	4209	0.21
//1078	Hashing	25	861	3236	0.27

//1080	Graduate Admission	30	736	3307	0.22
//1081	Rational Sum	20	776	2645	0.29
//1082	Read Number in Chinese	25	619	2276	0.27
//1085	Perfect Sequence	25	1026	3739	0.27
//1088	Rational Arithmetic	20	577	2009	0.29
//1095	Cars on Campus	30	588	2345	0.25
//1096	Consecutive Factors	20	700	2685	0.26
//1101	Quick Sort	25	653	2929	0.22

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int fee[25] = { 0 };
struct Record
{
	string name = "";
	int month = 0, day = 0, hour = 0, minute = 0, time = 0;
	bool is_online = false;
	bool is_vivid = false;
} rec[1001];

double caculate(int day, int hour, int minute)
{
	double total = fee[hour] * minute + fee[24] * 60 * day;
	for (int i = 0; i < hour; i++)
		total += fee[i] * 60;
	return total / 100.0;
}
bool cmp(Record a, Record b)
{
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 24; i++)
	{
		scanf("%d", &fee[i]);
		fee[24] += fee[i];
	}
	int N;
	scanf("%d", &N);
	Record t; char t1[10] = "off-line"; char t2[21] = "name";
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d:%d:%d:%d %s", &t2[0], &t.month, &t.day, &t.hour, &t.minute, &t1[0]);
		t.name = t2;
		t.time = t.day * 24 * 60 + t.hour * 60 + t.minute;
		if (t1[1] == 'n')t.is_online = true;
		else t.is_online = false;
		rec[i] = t;
	}
	sort(rec, rec + N, cmp);
	string Name = "";
	int day1, hour1, minute1;
	double Total_amount = 0.0;
	for (int i = 1; i < N; i++)
	{
		if (rec[i].name == rec[i - 1].name && rec[i - 1].is_online == true && rec[i].is_online == false && rec[i].is_vivid == false)
		{
			rec[i].is_vivid = true;
			rec[i - 1].is_vivid = true;
		}
	}
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (rec[i].is_vivid)rec[j++] = rec[i];
	}
	rec[j].name = Name;
	for (int i = 0; i < j; i++)
	{
		if (rec[i].name != Name)
		{
			Name = rec[i].name;
			day1 = rec[i].day, hour1 = rec[i].hour, minute1 = rec[i].minute;
			printf("%s %02d\n", &Name[0], rec[i].month);
		}
		else
		{
			if (!rec[i].is_online)
			{
				if (rec[i - 1].is_online)
				{
					int day2 = rec[i].day, hour2 = rec[i].hour, minute2 = rec[i].minute;
					int mi = (day2 - day1) * 24 * 60 + (hour2 - hour1) * 60 + (minute2 - minute1);
					double cost = caculate(day2, hour2, minute2) - caculate(day1, hour1, minute1);
					printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02f\n", day1, hour1, minute1, day2, hour2, minute2, mi, cost);
					Total_amount += cost;
				}
			}
			else
			{
				day1 = rec[i].day, hour1 = rec[i].hour, minute1 = rec[i].minute;
			}
		}
		if (rec[i].name != rec[i + 1].name)
		{
			printf("Total amount: $%.02f\n", Total_amount);
			Total_amount = 0;
		}
	}

	return 0;
}