class Solution {
public:     
    long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(to_string(n) + s);
    } // original number + reversed number = palindromic number 
    
    int largestPalindrome(int n)
    {
        if (n == 1) return 9;
        long long a = pow(10, n) - 1;
        long long aprime = pow(10, n-1);
        for (long long i = a; i >= aprime; i--) {
            long long cand = buildPalindrome(i);
            for (long long j = a; j*j >= cand; j--) {
                if (cand % j == 0 && cand / j <= a) {
                    return cand % 1337;
                }
            }
        }
        return -1;
    }
};