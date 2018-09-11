/*
1016 Phone Bills£¨25 point(s)£©
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (¡Ü1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word on-line or off-line.

For each test case, all dates will be within a single month. Each on-line record is paired with the chronologically next record for the same customer provided it is an off-line record. Any on-line records that are not paired with an off-line record are ignored, as are off-line records not paired with an on-line record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:
For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/
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