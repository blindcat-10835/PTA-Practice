/*
7-44 基于词频的文件相似度 （30 point(s)）
实现一种简单原始的文件相似度计算，即以两文件的公共词汇占总词汇的比例来定义相似度。为简化问题，这里不考虑中文（因为分词太难了），只考虑长度不小于3、且不超过10的英文单词，长度超过10的只考虑前10个字母。

输入格式:
输入首先给出正整数N（≤100），为文件总数。随后按以下格式给出每个文件的内容：首先给出文件正文，最后在一行中只给出一个字符#，表示文件结束。在N个文件内容结束之后，给出查询总数M（≤10
​4
​​ ），随后M行，每行给出一对文件编号，其间以空格分隔。这里假设文件按给出的顺序从1到N编号。

输出格式:
针对每一条查询，在一行中输出两文件的相似度，即两文件的公共词汇量占两文件总词汇量的百分比，精确到小数点后1位。注意这里的一个“单词”只包括仅由英文字母组成的、长度不小于3、且不超过10的英文单词，长度超过10的只考虑前10个字母。单词间以任何非英文字母隔开。另外，大小写不同的同一单词被认为是相同的单词，例如“You”和“you”是同一个单词。

输入样例:
3
Aaa Bbb Ccc
#
Bbb Ccc Ddd
#
Aaa2 ccc Eee
is at Ddd@Fff
#
2
1 2
1 3
输出样例:
50.0%
33.3%
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <string>
using namespace std;
void deal(string s, set<string> &set_confer)
{
	/*去尾*/
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (isalpha(s[i]))
		{
			s.erase(i + 1, s.size());
			break;
		}
	}
	/*尾部增加哨兵,随便一个非英文*/
	s.push_back('0');
	while (s.size() != 1)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (isalpha(s[i]))
			{
				s.erase(0, i);
				break;
			}
			/*如果到结尾‘0’处还没有出现一个英文，则整段丢掉，留下一个‘0’跳出while*/
			else if (i == s.size() - 1)
			{
				s.erase(0, s.size() - 1);
			}
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (!isalpha(s[i]))
			{
				string tmp = s.substr(0, i);
				if (i >= 10)tmp = tmp.substr(0, 10);
				if (i >= 3)set_confer.insert(tmp);
				s.erase(0, i);
				break;
			}
			else s[i] = tolower(s[i]);
		}
	}
	return;
}
int main(int argc, char const *argv[])
{
	int tmp;
	scanf("%d", &tmp);
	set<string> Set[1001];
	for (int i = 0; i < tmp; i++)
	{
		while (true)
		{
			string s;
			cin >> s;
			if (s == "#"&&s.size() == 1)break;
			deal(s, Set[i]);
		}
	}
	int n = 10000;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b, count = 0;
		cin >> a >> b;
		a--; b--;
		for (auto iter : Set[a])
		{
			if (Set[b].count(iter) != 0)
			{
				count++;
			}
		}
		printf("%.1f%%\n", count *100.0 / (Set[a].size() + Set[b].size() - count));
	}
	return 0;
}
/*
3
Aaa#Bbb##Ccc&&&
#
Bbb#@%@^!Ccc@#$ @#^@#^Ddd
#
Aaa2  $# @#$@ccc$ a123 Eee   $^@&@#$
is %#&@at@#$% Ddd@Fff%@#
#
2
1 2
1 3
*/