class Solution
{
public:
	int smallestRangeII(vector<int>& A, int K)
	{
		std::sort(A.begin(), A.end());
		int ret = A.back() - A.front();
		for (auto first = A.begin(), first2 = first + 1; first2 != A.end(); ++first, ++first2)
		{
			ret = std::min(ret, std::max(A.back() - K, *first + K) - std::min(A.front() + K, *first2 - K));
		}
		return ret;
	}
};