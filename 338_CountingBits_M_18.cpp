class Solution {
public:
    vector<int> countBits(int num) {
        // 0 1 2 3 4 5 6 7 8 9 10 11
        // 0 1 10 11 100 101 110 111 1000 1001 1010 1011
        // 0 1 1 2 1 2 2 3 1 2 2 
        // 11 = 8 + 3 = 1 + 2 = 3
        if (num == 0) {
            vector<int> temp1;
            temp1.push_back(0);
            return temp1;
        } // special case handling for num == 0
        else if (num == 1) {
            vector<int> temp2;
            temp2.push_back(0);
            temp2.push_back(1);
            return temp2;
        } // special case handling for num == 1
        int temp;
        temp = (num < 2) ? 2 : num;
        vector<int> dp(temp + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1; 
        for (int i = 3; i <= num; i++) {
            dp[i] = INT_MAX;
        } 
        int j = 0;
        int i = 1;
        while (i <= num) {
            i = pow(2, j);
            if (i<= num) dp[i] = 1;
            j++;
        } // when i is some number of pow(2, x), it would definitely have only 1 
        for (int i = 3; i <= num; i++)
        {
            if (dp[i] == INT_MAX)
            {
                int temp = log2(i);
                dp[i] = dp[pow(2, temp)] + dp[i - pow(2, temp)];
            }
        } //  numbers could be calculated from the sum of 1's from other two numbers
        return dp;
    }
};