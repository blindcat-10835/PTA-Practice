/*
7-14 电话聊天狂人 （25 point(s)）
给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

输入格式:
输入首先给出正整数N（≤10
​5
​​ ），为通话记录条数。随后N行，每行给出一条通话记录。简单起见，这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

输出格式:
在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

输入样例:
4
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832
输出样例:
13588625832 3
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
typedef long long ll;

bool cmp(pair<ll, ll> A, pair<ll, ll> B)
{
	if (A.second != B.second)
	{
		return A.second > B.second;
	}
	else
	{
		return A.first < B.first;
	}
}
int main(ll argc, char const *argv[])
{
	ll N = 100000;
	scanf("%d", &N);
	map<ll, ll> RecordMap;
	for (size_t i = 0; i < N; i++)
	{
		ll tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		RecordMap[tmp1]++;
		RecordMap[tmp2]++;
	}
	vector< pair<ll, ll> > RecordVector(N);
	for (auto iter : RecordMap)
	{
		RecordVector.push_back(make_pair(iter.first, iter.second));
	}
	sort(RecordVector.begin(), RecordVector.end(), cmp);
	cout << RecordVector[0].first << ' ' << RecordVector[0].second;
	int count = 0;
	for (auto iter : RecordVector)
	{
		if (iter.second == RecordVector[0].second)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count > 1)
	{
		cout << ' ' << count << endl;
	}
	else
	{
		cout << endl;
	}
	return 0;
}