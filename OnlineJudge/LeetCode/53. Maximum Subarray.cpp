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
typedef int OutType;
typedef vector<int> InType;
class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int length = nums.size();

		int tmpSum = 0;
		int Sum = -1;
		bool allNega = true;
		for (int i = 0; i < length; i++)
		{
			if (nums[i] >= 0)allNega = false;

			if (tmpSum >= 0)
			{
				tmpSum += nums[i];
			}
			else if (tmpSum < 0)
			{
				tmpSum = 0;
				tmpSum += nums[i];
			}
			if (tmpSum > Sum)
			{
				Sum = tmpSum;
			}
		}
		if (allNega)
		{
			sort(nums.begin(), nums.end());
			Sum = *(nums.end() - 1);
		}
		return Sum;
	}
};
int main(int argc, char const *argv[])
{
	InType S = { -1 ,-2 };
	Solution Condition;
	OutType Result = Condition.maxSubArray(S);
	cout << Result << endl;
	return 0;
}