class Solution
{
public:
	int numJewelsInStones(string J, string S)
	{
		int ret = 0;
		int m[100] = { 0 };

		for (auto j : S)
		{
			m[j - 'A']++;
		}
		for (auto i : J)
		{
			ret += m[i - 'A'];
		}
		return ret;
	}
};