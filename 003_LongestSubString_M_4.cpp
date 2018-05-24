class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		/*
		Space: O(m,n) where m is the size of alphabet and n is the size of string 
		Time: O(2n) -> we need to slide both l and r to the end of string 
		*/
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


		/*
		Space: O(min(m, n)) where m is the size of alphabet and n is the size of string 
		Time: O(n) 
		*/
		int n = s.length(), ans = 0;
        unordered_map<char, int> m; // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (m.find(s[j]) != m.end()) {
                i = max(m[s[j]]), i);
            }
            ans = max(ans, j - i + 1);
            m[s[j]] = j+1;;
        }
        return ans;

    }
};