class Solution {
public:
    int hammingDistance(int x, int y) {
		// 1:   0 0 0 1
		// 4:   0 1 0 0
		// 1^4: 0 1 0 1

		// By using XOR operation, 
		// different bits will be labeled as 1
		// identical bits will be labeled as 0 
        int z = x^y;
        int cnt = 0;
        while (z != 0) {
            if ((z & 1) == 1) cnt++;
			// (1^4):     0 1 0 1 
			//     1:     0 0 0 1
			// (1^4) & 1: 0 0 0 1

			// By using AND operation, 
			// we would checking the last bit one by one 
			// if AND operation returns 1, it means this 
			// position contains different bits. 
			// else, it means this position contains the
			// same bits 
            z = z >> 1;
			// z >> 1: 1 0 1

			// By using right-shift operation, 
			// we would be tossing out the last bit
			// after comparison, until z reaches 0
        }
        return cnt;
    }
};