/*
7-46 新浪微博热门话题 （30 point(s)）
新浪微博可以在发言中嵌入“话题”，即将发言中的话题文字写在一对“#”之间，就可以生成话题链接，点击链接可以看到有多少人在跟自己讨论相同或者相似的话题。新浪微博还会随时更新热门话题列表，并将最热门的话题放在醒目的位置推荐大家关注。

本题目要求实现一个简化的热门话题推荐功能，从大量英文（因为中文分词处理比较麻烦）微博中解析出话题，找出被最多条微博提到的话题。

输入格式:
输入说明：输入首先给出一个正整数N（≤10
​5
​​ ），随后N行，每行给出一条英文微博，其长度不超过140个字符。任何包含在一对最近的#中的内容均被认为是一个话题，如果长度超过40个字符，则只保留前40个字符。输入保证#成对出现。

输出格式:
第一行输出被最多条微博提到的话题，第二行输出其被提到的微博条数。如果这样的话题不唯一，则输出按字母序最小的话题，并在第三行输出And k more ...，其中k是另外几条热门话题的条数。输入保证至少存在一条话题。

注意：两条话题被认为是相同的，如果在去掉所有非英文字母和数字的符号、并忽略大小写区别后，它们是相同的字符串；同时它们有完全相同的分词。输出时除首字母大写外，只保留小写英文字母和数字，并用一个空格分隔原文中的单词。

输入样例:
2
This is a #This is a HotHot topic test of topic Another Test of topic.Another hot ! Hot topic This is a  This is a HotHot topic test of topic Another Test of topic.Another hot ! Hot topic   #
#he#;
输出样例:
Hot
2
And 1 more ...
*/
/*
注意，40个字符为无效条件。
这里学习一下map排序的方法：
使用pair；
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
bool cmp(pair<string, int> A, pair<string, int> B)
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

void deal(string s, map<string, int > &Map_confer)
{
	bool hasNoTopic = true;
	/*去尾*/
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '#')
		{
			s.erase(i + 1, s.size());
			hasNoTopic = false;
			break;
		}
	}
	if (hasNoTopic)
	{
		return;
	}
	/*cut off the head*/
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '#')
		{
			s.erase(0, i);
			break;
		}
	}
	map <string, bool> isVisited;
	while (s.size())
	{
		int begin_i = 0, end_i = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '#')
			{
				begin_i = i;
				break;
			}
		}
		for (int i = begin_i + 1; i < s.size(); i++)
		{
			if (s[i] == '#')
			{
				end_i = i;
				break;
			}
		}

		string topic;
		for (int i = begin_i + 1; i <= end_i - 1 && i <= begin_i + 40; i++)
		{
			if (isalnum(s[i]))
			{
				topic += tolower(s[i]);
			}
			else
			{
				if (isalnum(topic[topic.size() - 1]))
				{
					topic += ' ';
				}
			}
		}
		if (!isalnum(topic[topic.size() - 1]))
		{
			topic.pop_back();
		}

		topic[0] = toupper(topic[0]);
		if (isVisited.count(topic) == 0)
		{
			Map_confer[topic]++;
			isVisited[topic] = true;
		}
		s.erase(0, end_i + 1);
	}
	return;
}
int main(int argc, char const *argv[])
{
	int N = 100000;
	scanf("%d\n", &N);
	map<string, int>  Map;
	for (int i = 0; i < N; i++)
	{
		string s;
		getline(cin, s);
		s.resize(140);
		deal(s, Map);
	}
	vector <pair<string, int> >tmp;

	for (auto iter : Map)
	{
		tmp.push_back(make_pair(iter.first, iter.second));
	}
	sort(tmp.begin(), tmp.end(), cmp);
	cout << tmp[0].first << endl << tmp[0].second << endl;
	int count = 0;
	for (int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i].second == tmp[0].second)
		{
			count++;
		}
	}
	if (count)printf("And %d more ...\n", count);
	return 0;
}