/*
1007 Maximum Subsequence Sum（25 point(s)）
Given a sequence of K integers { N
​1
​​ , N
​2
​​ , ..., N
​K
​​  }. A continuous subsequence is defined to be { N
​i
​​ , N
​i+1
​​ , ..., N
​j
​​  } where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int se[10001] = { 0 };
	int length;
	cin >> length;
	int tmpSum = 0, tmpBegin = 0, tmpEnd = length;
	int Sum = -1, Begin = 0, End = length;
	bool allNega = true;
	for (int i = 0; i < length; i++)
	{
		cin >> se[i];
		if (se[i] >= 0)allNega = false;

		if (tmpSum >= 0)
		{
			tmpSum += se[i];
			tmpEnd = i;
		}
		else if (tmpSum < 0)
		{
			tmpSum = 0;
			tmpSum += se[i];
			tmpBegin = i;
			tmpEnd = i;
		}
		if (tmpSum > Sum)
		{
			Sum = tmpSum;
			Begin = tmpBegin;
			End = tmpEnd;
		}
	}
	if (allNega)
	{
		Sum = 0;
		Begin = 0; End = length - 1;
	}
	printf("%d %d %d", Sum, se[Begin], se[End]);
	return 0;
}