#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef vector < vector <int> > OutType;
typedef vector<int> InType;
class Solution_My_error_OLE
{
public:
	vector< vector<int> > threeSum(vector<int>& nums)
	{
		vector < vector <int> > ret;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)break;
			for (int j = i + 1; j < nums.size(); j++)
			{
				int tmp = nums[i] + nums[j];
				if (tmp > 0)break;
				if (find(nums.begin() + j + 1, nums.end(), -tmp) != nums.end())
				{
					vector<int> t = { nums[i], nums[j], -tmp };
					if (find(ret.begin(), ret.end(), t) == ret.end())
						ret.push_back({ nums[i],nums[j],-tmp });
				}
			}
		}
		sort(ret.begin(), ret.end());
		ret.erase(unique(ret.begin(), ret.end()), ret.end());
		return ret;
	}
};
class Solution
{
public:
	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int> > res;

		std::sort(num.begin(), num.end());

		for (int i = 0; i < num.size(); i++)
		{
			int target = -num[i];
			int front = i + 1;
			int back = num.size() - 1;

			while (front < back)
			{
				int sum = num[front] + num[back];

				// Finding answer which start from number num[i]
				if (sum < target)
					front++;

				else if (sum > target)
					back--;

				else
				{
					vector<int> triplet(3, 0);
					triplet[0] = num[i];
					triplet[1] = num[front];
					triplet[2] = num[back];
					res.push_back(triplet);

					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					while (front < back && num[front] == triplet[1]) front++;

					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && num[back] == triplet[2]) back--;
				}
			}

			// Processing duplicates of Number 1
			while (i + 1 < num.size() && num[i + 1] == num[i])
				i++;
		}

		return res;
	}
};
int main(int argc, char const *argv[])
{
	InType S = {};
	Solution Condition;
	OutType Result = Condition.threeSum(S);
	//cout << Result << endl;
	for (auto iter : Result)
	{
		cout << '[';
		for (auto i : iter)
		{
			cout << i << ',';
		}
		cout << ']' << endl;
	}
	return 0;
}