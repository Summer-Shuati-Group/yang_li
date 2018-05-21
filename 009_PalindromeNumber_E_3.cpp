class Solution {
public:
    bool isPalindrome(int x) {
		/*
		convert the original integer to a string
		and compare if it's a palindrome string

		Space: O(log10 n), where n is the size of the number
		Time: O(log10 n), where n is the size of the number
		*/
        if (x < 0) return false;
        string str = to_string(x);
        for (int i = 0; i < str.length() / 2; i++) {
            if (str[i] != str[str.length() - 1 - i]) {
                return false;
            }
        }
        return true;


		/*
		RULING OUT TWO OPTIONS: 
		1. negative numbers, negative sign would appear at the end of the number if reverted
		2. non-zero number with zero at its end, zero would appear at the front at the
		front if reverted. However, any non-zero does not have such property

		THEN: 
		if it is even, compare the first half of the number and second half of the number
		if it is odd, do the same thing and middle digit would always equal to itself 
		(by dividing 10, we can rule out the middle digit)

		Space: O(1)
		Time: O(log10 n), where n is the size of the number
		*/
		if (x < 0 || (x%10 == 0 && x != 0)) return false;
        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        
        return x==y || x == y / 10;
    }
};