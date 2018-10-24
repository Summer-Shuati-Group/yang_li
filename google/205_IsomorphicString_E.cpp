class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
        {
            return false;
        }

        map<char, char> m1;
        map<char, char> m2;
        
        for (int i = 0; i < s.length(); i++) {
            if (m1.find(s[i]) == m1.end()) {
                m1.insert(pair<char, char>(s[i], t[i]));
            }
            else {  
                if (m1[s[i]] != t[i]) {
                    return false;
                }
            } 
        } // test whether each character in s[i] corresponds to t[i]
        
        for (int i = 0; i < t.length(); i++) {
            if (m2.find(t[i]) == m2.end()) {
                m2.insert(pair<char, char>(t[i], s[i]));
            }
            else{
                if (m2[t[i]] != s[i]) {
                    return false;
                }
            }
        } // test whether each character in t[i] corresponds to s[i]

        return true;
    }
};