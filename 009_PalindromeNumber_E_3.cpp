class Solution {
public:
	/*
	convert the original integer to a string
	and compare if it's a palindrome string
	*/
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        for (int i = 0; i < str.length() / 2; i++) {
            if (str[i] != str[str.length() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};