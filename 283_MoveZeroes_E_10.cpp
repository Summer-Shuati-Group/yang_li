class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		/* 1. By finding the first nonzero element, we would swap it with
		the slow pointer */
        int i = 0; int j = 0;
        while (i < nums.size()) {
            if (nums[i]) {
                swap(nums[i], nums[j]);
				j++;
            }
            i++;
        }
		// loop invariant: 
		// 1. All elements before the slow pointer (j) are non-zeroes.
		// 2. All elements between the current (i) and slow pointer (j) are zeroes.
		// optimal solutions with the fewest possible operations



		/* 2. Time: O(n) */
		int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i]) {
                nums[j] = nums[i];
                j++;
            }
        } 
		// If the current element is not 0, then we need to
    	// append it just in front of last non 0 element we found. 
        
        while (j < nums.size()) {
            nums[j] = 0;
            j++;
        }
		// After we have finished processing new elements,
    	// all the non-zero elements are already at beginning of array.
    	// We just need to fill remaining array with 0's.
    }
};