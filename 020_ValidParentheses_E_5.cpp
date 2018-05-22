class Solution {
public:
    bool isValid(string s) {
		/*
		stack经典题: 
		Space: O(n), where n is the length of the string -> worst-case upper-bound
		Time: O(n), where n is the length of the string  -> worst-case upper-bound
		*/
        stack<char> st;
        int i = 0;
        while (i != s.length()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else if (st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') || (s[i] == '}' && st.top() != '{')) {
                return false;
            }
            else {st.pop();}
            i++;
        }
        return st.empty();
    }
};