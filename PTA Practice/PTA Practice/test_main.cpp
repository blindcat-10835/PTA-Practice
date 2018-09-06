//1014	Waiting in Line	30	882	3967	0.22
//1015	Reversible Primes	20	1334	4941	0.27
//1016	Phone Bills	25	947	4410	0.21
//1017	Queueing at Bank	25	710	2809	0.25
//1018	Public Bike Management	30	920	3695	0.25
//1021	Deepest Root	25	1059	3908	0.27
//1025	PAT Ranking	25	1444	5228	0.28
//1026	Table Tennis	30	372	2210	0.17

//1028	List Sorting	25	1020	3553	0.29
//1029	Median	25	950	10330	0.09
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
using namespace std;
const int N = 10002;
const int INF = 999999;

struct Window
{
	int list[N] = { 0 };
	int head = 1;
	int end = 0;
};
Window win[25];

int cost[N] = { 0 };
int EndTime[N] = { 0 };

int inQ(int win_i, int cust_i)
{
	win[win_i].end++;
	int curEnd = win[win_i].end;
	if (win[win_i].list[curEnd - 1] >= 540)
	{
		win[win_i].list[curEnd] = INF;
		EndTime[cust_i] = INF;
	}
	else
	{
		win[win_i].list[curEnd] = cost[cust_i] + win[win_i].list[curEnd - 1];
		EndTime[cust_i] = win[win_i].list[curEnd];
		return 0;
	}
}
int main(int argc, char const *argv[])
{
	int  Windows, Capacity, Customers, Queries;
	cin >> Windows >> Capacity >> Customers >> Queries;
	for (int Customer_i = 1; Customer_i <= Customers; Customer_i++)
	{
		scanf("%d", &cost[Customer_i]);
		if (Customer_i <= Windows * Capacity)
		{
			//只入队
			int curWin = (Customer_i - 1) % Windows + 1;
			inQ(curWin, Customer_i);
		}
		else
		{
			//既有入队又有出队
			int curWin = -1;
			int tmpPopTime = INF + 1;
			for (int i = 1; i <= Windows; i++)
			{
				if (win[i].list[win[i].head] < tmpPopTime)
				{
					tmpPopTime = win[i].list[win[i].head];
					curWin = i;
				}
			}
			win[curWin].head++;
			inQ(curWin, Customer_i);
		}
	}
	for (int i = 1; i <= Queries; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (EndTime[tmp] < INF)
		{
			int hour = EndTime[tmp] / 60 + 8, minute = EndTime[tmp] % 60;
			printf("%02d:%02d\n", hour, minute);
		}
		else
		{
			printf("Sorry\n");
		}
	}

	return 0;
}
//2 2 7 7
//1 2 6 4 3 534 2
//1 2 3 4 5 6 7
//08:01
//08 : 02
//08 : 07
//08 : 06
//08 : 10
//17 : 00
//Sorry

//2 2 8 8
//1 2 6 4 3 534 2 531
//1 2 3 4 5 6 7 8
//08:01
//08 : 02
//08 : 07
//08 : 06
//08 : 10
//17 : 00
//Sorry