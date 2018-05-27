class Solution {
public:
    int maxProfit(vector<int>& prices) {
		// 1. dynamic programming: 'careful brute force'
		// Time: O(n^2)
        int dp[200000];
        dp[0] = 0;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                if (prices[i] > prices[j]) {
                    dp[i] = max(dp[i], prices[i] - prices[j]);
                }
            }
            maxprofit = max(maxprofit, dp[i]);
        }
        
        return maxprofit;


		int minprofit = INT_MAX;
        int maxp = 0;
        for (int i = 0; i < prices.size(); i++) {
            minprofit = min(prices[i], minprofit); // update the lowest price 
            maxp = max(maxp, prices[i] - minprofit); // update the maximum profit 
        }
        return maxp;
    }
};