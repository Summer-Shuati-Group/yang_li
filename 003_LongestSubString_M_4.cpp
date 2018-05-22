class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        	if (s.length() <= 1) return s.length();
		int l = 0;
		int r = 0;
		int ans = 0;
		unordered_set<char> container;
		while (l < s.length() && r < s.length())
		{
			if (container.find(s[r]) == container.end())
			{
				// find new characters
				container.insert(s[r++]);
				ans = max(ans, r - l);
			}
			else
			{
				container.erase(s[l++]);
			}
		}
		return ans;
    }
};