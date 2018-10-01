/*
4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

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
/*关闭io同步加快cin速度！*/
static int x = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
/*初次思路：
使用双指针归并
*/
class Solution_my
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int n = (nums1.size() + nums2.size() + 1) / 2;
		int Case = (nums1.size() + nums2.size()) % 2;
		if (Case == 1)
		{
			int count = 0;
			double ret = 0.0;
			int p1 = 0, p2 = 0;
			while (count < n&&p1 < nums1.size() && p2 < nums2.size())
			{
				count++;
				if (nums1[p1] < nums2[p2])
				{
					ret = nums1[p1];
					p1++;
				}
				else
				{
					ret = nums2[p2];
					p2++;
				}
			}
			while (count < n&&p1 < nums1.size())
			{
				count++;
				ret = nums1[p1];
				p1++;
			}
			while (count < n&&p2 < nums2.size())
			{
				count++;
				ret = nums2[p2];
				p2++;
			}
			return ret;
		}
		else
		{
			int count = 0;
			double ret = 0.0;
			int p1 = 0, p2 = 0;
			while (count < n&&p1 < nums1.size() && p2 < nums2.size())
			{
				if (nums1[p1] < nums2[p2])
				{
					count++;
					ret = nums1[p1];
					p1++;
				}
				else
				{
					count++;
					ret = nums2[p2];
					p2++;
				}
			}
			while (count < n&&p1 < nums1.size())
			{
				count++;
				ret = nums1[p1];
				p1++;
			}
			while (count < n&&p2 < nums2.size())
			{
				count++;
				ret = nums2[p2];
				p2++;
			}
			if (p1 < nums1.size() && p2 < nums2.size())
			{
				if (nums1[p1] < nums2[p2])
				{
					ret += nums1[p1];
				}
				else
				{
					ret += nums2[p2];
				}
			}
			else if (p1 < nums1.size())
			{
				ret += nums1[p1];
			}
			else
			{
				ret += nums2[p2];
			}
			return ret / 2.0;
		}
	}
};
/*标准答案：
考虑很多细节，
二分查找
然后是一些特殊情况
*/
class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int len1 = nums1.size(), len2 = nums2.size();
		if (len1 > len2)
		{
			vector<int> s1 = nums1;
			nums1 = nums2;
			nums2 = s1;
		}
		int m = nums1.size(), n = nums2.size();
		int i = 0, i_max = nums1.size(), i_min = 0;
		int j = (m + n) / 2 - i;
		double ret = 0.0;
		int  halfLen = (m + n) / 2;

		while (i_min <= i_max)
		{
			i = (i_min + i_max) / 2;
			j = halfLen - i;
			if (i > 0 && nums1[i - 1] > nums2[j])
			{
				i_max = i - 1;
			}
			else if (i<m && nums2[j - 1] > nums1[i])
			{
				i_min = i + 1;
			}
			else
			{
				break;
			}
		}
		int maxLeft = 0;
		if (i == 0) { maxLeft = nums2[j - 1]; }
		else if (j == 0)
		{
			maxLeft = nums1[i - 1];
		}
		else
		{
			maxLeft = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
		}
		int minRight = maxLeft;
		if (i == m)
		{
			minRight = nums2[j];
		}
		else if (j == n)
		{
			minRight = nums1[i];
		}
		else
		{
			minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
		}
		if ((m + n) % 2 == 0)
		{
			ret = (minRight + maxLeft) / 2.0;
		}
		else
		{
			ret = minRight;
		}
		return ret;
	}
};
int main(int argc, char const *argv[])
{
	vector<int> n1 = { 1,2,2 }, n2 = { 1,2,3 };
	Solution s;
	double p = s.findMedianSortedArrays(n1, n2);
	cout << p;
	return 0;
}