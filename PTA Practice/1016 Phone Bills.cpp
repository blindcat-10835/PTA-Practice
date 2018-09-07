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
	bool is_valid = false;
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
		if (rec[i].name == rec[i - 1].name && rec[i - 1].is_online == true && rec[i].is_online == false && rec[i].is_valid == false)
		{
			rec[i].is_valid = true;
			rec[i - 1].is_valid = true;
		}
	}
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (rec[i].is_valid)rec[j++] = rec[i];
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