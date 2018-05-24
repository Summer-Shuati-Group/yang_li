class Solution {
public:
	int maxSubarrayCross(vector<int>& nums, int l, int r, int mid) {
        int sum = 0; int left_sum = INT_MIN; int right_sum = INT_MIN;
        for (int i = mid; i >= l; i--) {
            sum += nums[i];
            if (sum > left_sum) {
                left_sum = sum;
            }
        } // look for the largest sum of the left subarray 
        sum = 0;
        for (int i = mid + 1; i <= r; i++) {
            sum += nums[i];
            if (sum > right_sum) {
                right_sum = sum;
            }
        } // look for the largest sum of the right subarray
        return left_sum + right_sum;
    } // used to compute the largest sum of the subarray from l to r 
	  // Time: O(n), scan through the interval from l to r
    
    int dac(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l]; 
		// if divided into only one element, just return this element
        int mid = l + (r - l) / 2;
        return max(max(dac(nums, l, mid), dac(nums, mid + 1, r)), maxSubarrayCross(nums, l, r, mid));
    } // divide-and-conquer: divide into the left subsection and right subsection
	// then compute the largest sum for each subsection 

    int maxSubArray(vector<int>& nums) {
		/* brute force: scan through the array twice 
		Time: O(n^2) */
        int max = nums[0];
        int temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                temp += nums[j];
                if (temp > max) {
                    max = temp;
                }
            }
            temp = 0;
        }
        return max;


		/* Divide-and-Conquer: Time: O(nlog(n)) */
		return dac(nums, 0, nums.size() - 1);


		/* Dynamic Programming (Kadane's Algorithm): Time: O(n) 
		Inductive Thinking: if we know aximum subarray sum ending at position i, 
		the maximum subarray sum ending at position i+1 either includes the maximum subarray 
		sum ending at position i as a prefix, or it doesn't. 

		In other words, B_{i+1} = max(A_{i+1}, A_{i+1} + B_{i});
		*/
		int dp[nums.size()];
        int largest = dp[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            largest = max(largest, dp[i]);
        }
        
        return largest;

		/* 
		Some properties of Maximum Subarray Problem: 
		1. If the array contains all non-positive numbers, 
		then the solution is the number in the array with the smallest magnitude.
		2. If the array contains all non-negative numbers, 
		then the problem is trivial and the maximum sum is the sum of all the elements in the list.
		3. An empty set is not valid.
		4. There can be multiple different sub-arrays that achieve the same maximum sum to the problem.
		*/
    }
};