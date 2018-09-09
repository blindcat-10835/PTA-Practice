/*
7-3 树的同构（25 point(s)）
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。

现给定两棵树，请你判断它们是否是同构的。
输入格式:
输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。

输出格式:
如果两棵树是同构的，输出“Yes”，否则输出“No”。

输入样例1（对应图1）：
8
a 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
输出样例1:
Yes
输入样例2（对应图2）：
8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4
输出样例2:
No
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
typedef char Elementtype;
typedef int PtrToTree;
const int MAXLENGTH = 1000;

//使用数组来表示树，则树根==序号，index == root;
struct TreeNode
{
	Elementtype Value = 0;
	PtrToTree Left = -1;
	PtrToTree Right = -1;
};
void getTree(vector<TreeNode> &T)
{
	int nodeN = T.size();
	for (int i = 0; i < nodeN; i++)
	{
		char left, right;
		/*if use "%c instead of "%s"  it will ! get '\n'or' '*/
		scanf("%c %c %c\n", &T[i].Value, &left, &right);
		if (left != '-')T[i].Left = left - '0';
		if (right != '-')T[i].Right = right - '0';
	}
}

PtrToTree FindElement(vector<TreeNode> T1, char Value)
{
	int root = -1;
	for (int i = 0; i < T1.size(); i++)
	{
		if (T1[i].Value == Value)
		{
			root = i;
			break;
		}
	}
	return root;
}
PtrToTree FindTreeRoot(vector<TreeNode> T1)
{
	int root = -1;
	vector<bool> hasParent(T1.size(), false);
	for (TreeNode i : T1)
	{
		if (i.Left != -1)hasParent[i.Left] = true;
		if (i.Right != -1)hasParent[i.Right] = true;
	}
	for (int i = 0; i < hasParent.size(); i++)
	{
		if (!hasParent[i])
		{
			root = i;
			break;
		}
	}
	return root;
}
bool Juge(vector<TreeNode> T1, vector<TreeNode> T2)
{
	for (int i = 0; i < T1.size(); i++)
	{
		PtrToTree T2_i = FindElement(T2, T1[i].Value);
		if (T2_i == -1)return false;
		char LValue1 = '-', RV1 = '-', LV2 = '-', RV2 = '-';
		if (T2[T2_i].Left != -1)LValue1 = T2[T2[T2_i].Left].Value;
		if (T2[T2_i].Right != -1)	RV1 = T2[T2[T2_i].Right].Value;
		if (T1[i].Right != -1)	LV2 = T1[T1[i].Right].Value;
		if (T1[i].Left != -1)	RV2 = T1[T1[i].Left].Value;
		if (LValue1 == LV2 && RV1 == RV2)
		{
		}
		else if (LValue1 == RV2 && LV2 == RV1)
		{
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	/*分配树的空间,输入树*/
	int N1 = 0, N2 = 0;
	scanf("%d\n", &N1);
	vector<TreeNode> T1(N1);
	getTree(T1);
	scanf("%d\n", &N2);
	vector<TreeNode> T2(N2);
	getTree(T2);
	/*判断是否同构*/
	if (Juge(T1, T2))cout << "Yes\n";
	else cout << "No\n";
	return 0;
}