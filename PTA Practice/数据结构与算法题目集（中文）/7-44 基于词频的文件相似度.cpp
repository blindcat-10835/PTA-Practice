#include<bits/stdc++.h>
#include<cmath>
#include <set>
using namespace std;
int main()
{
	set<string> Set[110];
	int n;
	char ts[15], s[100];
	scanf("%d", &n);
	int set_i = 1;
	while (~scanf("%s", s))
	{
		int len = strlen(s), k = 0;
		if (s[0] == '#' && len == 1)
		{
			if (set_i++ == n) break;
		}

		for (int i = 0; i < len; i++)
		{
			if (s[i] >= 'a'&&s[i] <= 'z') s[i] = toupper(s[i]);
		}

		for (int i = 0, f = 0; i < len; i++)
		{
			char c = s[i];
			if (isupper(c))
			{
				if (f) continue;
				ts[k++] = c;
				if (k >= 10) // ����10�����ַ��ָ�else�ᴦ��û���ַ��ָ���ߴ���
				{
					ts[k++] = '\0';
					f = 1;
					k = 0; // ������for������жϻ���
					Set[set_i].insert(ts);
				}
			}
			else // ���ַ��ָ�
			{
				if (!f) // û����10
				{
					if (k >= 3)
					{
						ts[k++] = '\0';
						Set[set_i].insert(ts);
					}
				}
				else; // ����10
				f = 0;
				k = 0;
			}
		}

		if (k >= 3)
		{
			ts[k++] = '\0';
			Set[set_i].insert(ts);
		}
	}
	/*----------------------*/
	int m, a, b; scanf("%d", &m);
	for (int i = 0, up; i < m; i++)
	{
		up = 0;
		scanf("%d%d", &a, &b);
		for (auto iter : Set[a])
		{
			if (Set[b].count(iter) != 0)
			{
				up++;
			}
		}
		printf("%.1f%%\n", up*1.0 / (Set[a].size() + Set[b].size() - up) * 100);
	}
	return 0;
}