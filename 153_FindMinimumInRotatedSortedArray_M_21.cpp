class Solution {
public:
    int findMin(vector<int>& nums) {
		/* Time: O(n logn) */
		sort(nums.begin(), nums.end());
		return nums[0];

		/* Time: O(n) */
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i+1] < nums[i]) {
                return min(nums[0], nums[i+1]);
            }   
        }
        return nums[0];

		/* Time: O(log n) */
		int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            if (nums[start]<nums[end])
                return nums[start];
            
            int mid = (start+end)/2;
            
            if (nums[mid]>=nums[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};