/*
1009 说反话 (20)（20 point(s)）
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：

Hello World Here I Come
输出样例：

Come I Here World Hello
*/
/*
pat 1009. 说反话 (20) - 琴影 - 博客园
https://www.cnblogs.com/qinduanyinghua/p/5494608.html
blindact:
这个方法十分巧妙地运用了'\0'，
实际上是不是可以用stack来做这件事？注意到他是先入后出
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	char c[41][81], tmp;
	int i = 0, j = 0;
	while ((tmp = getchar()) != '\n')
	{
		if (tmp == ' ')
		{
			c[i++][j] = '\0';
			j = 0;
		}
		else c[i][j++] = tmp;
	}
	c[i][j] = '\0';
	cout << c[i--];
	while (i >= 0)
	{
		cout << ' ' << c[i--];
	}
	return 0;
}