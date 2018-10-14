class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> ans;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            ans[s[i]] = 0;
        } // set the number of occurrences as 0

        for (int i = 0; i < s.length(); i++) {
            ans[s[i]]++;
        } // count the number of occurrences

        for (int i = 0; i < ans.size(); i++) {
            cout << "ans[i]: " << ans[i] << endl;
            if (ans[i] % 2) {
                cnt++;
            }
        }
        return ((cnt == 1 && s.length() % 2) || (cnt == 0 && s.length() % 2 == 0));
		// odd length: one with odd occurrences and others with even occurrences
		// even length: every with even occurrences
    }
};