/*1005 继续(3n+1)猜想 (25)（25 point(s)）
卡拉兹(Callatz)猜想：

对任何一个自然数n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3n+1)砍掉一半。这样一直反复砍下去，最后一定在某一步得到n=1。卡拉兹在1950年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证(3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展……

卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(&lt100)，第2行给出K个互不相同的待验证的正整数n(1&ltn<=100)的值，数字间用空格隔开。

输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

输入样例：

6
3 5 6 7 8 11
输出样例：

7 6
*/
#include <iostream>
#include <string>
#define MAX 102
using namespace std;

int main(int argc, char const *argv[])
{
	int length = 0, s[MAX] = { 0 };
	cin >> length;
	int i = length;
	/*input*/
	while (i--)
	{
		cin >> s[i];
	}
	/*delete the covered numbers*/
	i = length;
	while (i--)
	{
		int tmp = s[i];
		while (tmp != 1)
		{
			if (tmp % 2 == 0)tmp /= 2;
			else tmp = (tmp * 3 + 1) / 2;
			int j = length;
			while (j--)
			{
				if (s[j] == tmp)s[j] = 1;
			}
		}
	}

	/*sort the array */
	i = length;
	int sort[MAX] = { 1 };
	while (i--)
	{
		if (s[i] != 1)sort[s[i]] = s[i];
	}
	/*find the last element*/
	i = 1;
	while (sort[i] == 1 || sort[i] == 0)
	{
		i++;
	}
	int last = i;
	/*print*/
	i = MAX;
	while (i--)
	{
		if (sort[i] != 1 && sort[i] && i != last)cout << sort[i] << " ";
		else if (i == last)
		{
			cout << sort[i];
		}
	}

	return 0;
}