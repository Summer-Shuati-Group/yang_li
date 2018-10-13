class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        // write your code here
        vector<string> v;
        if (s.empty()) return v;
    	for (int i = 0; i < s.length() - 1; i++) {
    		if (s[i] == s[i+1] && s[i] == '+') {
    			string str = s;
    			s.replace(i, 2, "--");
    			v.push_back(s);
    			s = str;
    		}
    	}
    	return v;
    }
};