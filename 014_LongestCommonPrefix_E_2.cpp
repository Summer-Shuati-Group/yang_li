class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = 0; // tracing corresponding chars
	string result;
	if (strs.empty())
		return result;
	if (strs.size() == 1)
		return strs[0];
	while (true)
	{
		int j = 1;
		while (pos != strs[0].length() && strs[j][pos] == strs[0][pos])
		{
            if (j == strs.size() - 1) {
                result += strs[0].substr(pos,1);
                pos++;
                break;
            }
			j++;
		}
		if (strs[0][pos] != strs[j][pos]) break;
        else if (pos == strs[0].length()) return strs[0];
	}
	return result;
    }
};