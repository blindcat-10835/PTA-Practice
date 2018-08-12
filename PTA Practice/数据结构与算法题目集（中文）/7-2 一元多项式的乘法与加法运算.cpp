/*7-2 一元多项式的乘法与加法运算（20 point(s)）
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0*/
#include <iostream>
using namespace std;
typedef struct List* PtrToList;
struct List
{
	int xisu;
	int zhishu;
	PtrToList next;
};
PtrToList Make_List()
{
	int length1;
	cin >> length1;
	List S1[length1];
	for (int i = 0; i < length1; i++)
	{
		cin >> S1[i].xishu >> S1[i].zhishu;
	}
}
int main(int argc, char const *argv[])
{
	cin >> length2;
	List S2[length2];
	for (int i = 0; i < length2; i++)
	{
		cin >> S2[i].xishu >> S2[i].zhishu;
	}
	return 0;
}