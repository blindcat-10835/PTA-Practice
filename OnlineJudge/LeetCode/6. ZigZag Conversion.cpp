class Solution
{
public:
	string convert(string s, int numRows)
	{
		vector<string> T(numRows, "");
		int q = 1;
		if (numRows == 1)return s;
		bool inorder = true;
		for (int i = 0; i < s.size(); i++)
		{
			T[q - 1] = T[q - 1] + s[i];
			if (inorder)
			{
				q++;
				if (q == numRows)inorder = false;
			}
			else
			{
				q--;
				if (q == 1)inorder = true;
			}
		}
		string t = "";
		for (auto i : T)
			t = t + i;
		return t;
	}
};