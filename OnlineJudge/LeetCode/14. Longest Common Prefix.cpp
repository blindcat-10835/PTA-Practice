class Solution
{
public:
	string longestCommonPrefix(vector<string> strs)
	{
		if (strs.size() == 0)return "";
		//∞¥≥§∂»≈≈–Ú
		//sort(strs.begin(), strs.end(), [](string A, string B) { return A.size() < B.size(); });
		int common = 0;
		for (common = 0; common < strs[0].size(); common++)
		{
			char tmp = strs[0][common];
			for (int j = 1; j < strs.size(); j++)
			{
				if (strs[j][common] != tmp)return strs[0].substr(0, common);
			}
		}
		return strs[0].substr(0, common);
	}
};