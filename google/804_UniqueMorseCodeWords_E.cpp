class Solution
{
  public:
	static bool cmp(const string &a, const string &b)
	{
		if (a.length() != b.length())
			return a.length() < b.length();
		else
		{
			for (int i = 0; i < a.length(); i++)
			{
				if (a[i] != b[i])
				{
					return (a[i] < b[i]);
				}
			}
		}
		return false;
		// why return false ? 
	}

	int uniqueMorseRepresentations(vector<string> &words)
	{
		if (words.empty())
			return 0;
		vector<string> v = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // 0 - 25
		vector<string> ans;
		for (int i = 0; i < words.size(); i++)
		{
			string str;
			for (int j = 0; j < words[i].length(); j++)
			{
				str += v[words[i][j] - 'a'];
			}
			ans.push_back(str);
		}

		sort(ans.begin(), ans.end(), cmp);

		int cnt = 1;
		for (int i = 0; i < ans.size() - 1; i++)
		{
			if (ans[i] != ans[i + 1])
			{
				cnt++;
			}
		}

		return cnt;
	}
};