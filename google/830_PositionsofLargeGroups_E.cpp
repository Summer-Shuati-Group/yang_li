vector<vector<int>> largeGroupPositions(string S)
{
	vector<vector<int>> v;
	vector<int> vi;
	int count = 1;
	int start = 0;
	for (int i = 0; i < S.length() - 1; i++)
	{
		if (S[i] == S[i + 1])
		{
			count++;
		}
		else
		{
			if (count >= 3)
			{
				vi.push_back(start);
				vi.push_back(i);
				v.push_back(vi);
				vi.clear();
			}
			count = 1;
			start = i + 1;
		}
	}
	if (count >= 3)
	{
		vi.push_back(start);
		vi.push_back(S.length() - 1);
		v.push_back(vi);
		vi.clear();
	}
	return v;
}