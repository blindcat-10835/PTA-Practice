/*
7-5 ���е�·����25 point(s)��
��һϵ�и������ֲ���һ����ʼΪ�յ�С����H[]����������������±�i����ӡ��H[i]��������·����

�����ʽ:
ÿ����Ե�1�а���2��������N��M(��1000)���ֱ��ǲ���Ԫ�صĸ������Լ���Ҫ��ӡ��·����������һ�и�������[-10000, 10000]�ڵ�N��Ҫ������һ����ʼΪ�յ�С���ѵ����������һ�и���M���±ꡣ

�����ʽ:
�������и�����ÿ���±�i����һ���������H[i]��������·���ϵ����ݡ����ּ���1���ո�ָ�����ĩ�����ж���ո�

��������:
5 3
46 23 26 24 10
5 4 3
�������:
24 23 10
46 23 10
26 10
*/

/*
С���Ѵ�1��ʼ������
�������ʾ
����֮������Ϊ������ϵ
ע��ѧϰС���ѵĵ�������
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
using namespace std;

typedef int Elementtype;
typedef int PtrToTree;
const int MAXLENGTH = 1000;
const int null = 0;

//ʹ����������ʾ����������==��ţ�index == root;
struct TreeNode
{
	Elementtype Value = null;
	PtrToTree Left = null;
	PtrToTree Right = null;
};
const int INF = -10000 - 1;
int main(int argc, char const *argv[])
{
	int N = 1000, M = 1000;
	scanf("%d", &N);
	scanf("%d", &M);
	vector<int> MinHeap(N + 1, INF);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &MinHeap[i]);
		/*ע��ѧϰС���ѵĵ�������*/
		for (int j = 1; j <= i; j++)
		{
			if (MinHeap[j] < MinHeap[j / 2])
			{
				int tmp = MinHeap[j];
				MinHeap[j] = MinHeap[j / 2];
				MinHeap[j / 2] = tmp;
				j = 0;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		while (tmp != 1)
		{
			cout << MinHeap[tmp] << " ";
			tmp /= 2;
		}
		cout << MinHeap[tmp] << endl;
	}
	return 0;
}