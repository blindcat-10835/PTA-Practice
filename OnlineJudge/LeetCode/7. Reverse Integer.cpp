class Solution
{
public:
	int reverse(int x)
	{
		int ret = 0;
		while (x)
		{
			int y = ret * 10;
			if (y / 10 != ret)return 0;
			ret = y + x % 10;
			x = x / 10;
		}
		return ret;
	}
};