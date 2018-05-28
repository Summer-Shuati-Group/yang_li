class Solution {
public:    
    int addDigits(int num) {
		// Recursion: 
        if (num < 10) return num;
        int a = addDigits(num/10);
        int b = addDigits(num%10);
        return addDigits(a + b);

		// digital root method: 
		return 1 + (num-1) % 9;
    }
};