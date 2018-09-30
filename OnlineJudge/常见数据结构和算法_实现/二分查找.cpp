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

typedef int ElementType;

/*二分查找，传入数组，待查找元素，数组长度，返回该元素所在位置下标,找不到则返回-1*/
ElementType BinarySearch(const vector<ElementType> A, ElementType X)
{
	int Left = 0, Right = A.size(), Mid = (Left + Right) / 2;
	while (Left <= Right || X != A[Mid])
	{
		Mid = (Left + Right) / 2;
		if (X > A[Mid])
		{
			Left = Mid + 1;
		}
		else if (X < A[Mid])
		{
			Right = Mid - 1;
		}
	}
	if (Left > Right)
	{
		return -1;
	}
	else
	{
		return Mid;
	}
}