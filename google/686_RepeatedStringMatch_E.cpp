class Solution {
public:
	/* 1. repeat A to find B  */
    int repeatedStringMatch(string A, string B) {
        int cnt = 1;
        string t = A;
        while (t.length() < B.size())
        {
            t = t + A;
            ++cnt;
        } 
		// it is only possible when the string length of A is longer than that of B, B could become the substring of A. Therefore, we would increase the length of A to be larger than or equal to that of B.
        if (t.find(B) != string::npos)
        {
            return cnt;
        }
		// as there might exist the case like a = "abc" and b = "cab" where the lengths of a and b are identical, we need to repeat string a one more time to find string b
        t = t+A;
        if (t.find(B) != string::npos)
        {
            return cnt + 1;
        }
        else
        {
            return -1;
        }
    }


	/* 2. repeat A no more B.length() / A.length() + 2 times to find B */
	int repeatedStringMatch(string A, string B) {
        string t = A;
        for (int i = 1; i <= B.length() / A.length() + 2; i++) {
            if (t.find(B) != string::npos) {
                return i;
            }
            t = t + A;
        }
        return -1;
    }

	/* 3. the most confusing solution  */
	int repeatedStringMatch(string A, string B) {
        int m = A.size(), n = B.size();
        for (int i = 0; i < m; ++i) {
            int j = 0;
            while (j < n && A[(i + j) % m] == B[j]) ++j;
			// 1. make sure j is smaller than n 
			// 2. we correspond each character in A to B
            if (j == n) return (i + j - 1) / m + 1;
			// if j == n, it means that all the chars in A match up with those in B.
        }
        return -1;
    }
};