class Solution {
public:
    int rob(vector<int>& nums) {
		/* Dynamic Programming:
		Time: O(n)
		Space: O(n) */
        if (nums.empty()) return 0;
        int dp[nums.size() + 1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
		// the first two days are respectively their own values
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
			// bite-size decision: rob i or not 
			// yes, dp[i-2] + nums[i];
			// no, dp[i-1]
        }
        return dp[nums.size() - 1];


		/*
		update the max value of a and b alternatively
		check whether to include current number nums[i]
		*/
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2) {
                b = max(b + nums[i], a);
            }
            else {
                a = max(a + nums[i], b);
            }
        }
        return max(a, b);
    }
};