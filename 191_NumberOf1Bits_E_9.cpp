class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
			// first method: 
			// 1. determine if the last bit of n is 1, ++ if yes
			// 2. cut the last bit by bitwise rightshift 
            if (n & 1) cnt++;
            n >>= 1;

			// second method: 
			// doing a bit-wise AND of n and n - 1 
			// flips the least-significant 1-bit in n to 0
			// which is faster, because we do not have to
			// check every bit 
			n = n & (n-1);
			cnt++;
        }
        return cnt;
    }
};