class Solution {
public:
    int minDistance(string word1, string word2) {
		// classical dp question on sequence alignment 
		// Space Complexity is currently O(mn), but can be 
		// improve to O(2m + m + n) = O(m + n) if only using
		// two columns, which is the minimum possible space complexity
        int len1 = word1.length();
        int len2 = word2.length();
        int dp[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) 
        {
            dp[i][len2] = len1- i;
        }
        for (int j = 0; j <= len2; j++) 
        {
            dp[len1][j] = len2 - j;
        }
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }
                else {
                    dp[i][j] = 1 + min(min(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};