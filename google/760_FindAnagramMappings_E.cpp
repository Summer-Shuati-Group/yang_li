class Solution
{
  public:
	vector<int> anagramMappings(vector<int> &A, vector<int> &B)
	{
		map<int, int> m; 
		// use a map to find elements by key in a faster way
		vector<int> v;
		for (int i = 0; i < B.size(); i++)
		{
			m[B[i]] = i;
		}
		for (int i = 0; i < A.size(); i++)
		{
			v.push_back(m.find(A[i])->second);
		}
		return v;
	}
};