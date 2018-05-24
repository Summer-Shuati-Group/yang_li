class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		/*
		1. sort the array, 
		2. minimum of the pairs would have index 0, 2, 4, 6, 8, .... 
		3. just add up all the elements by every 2 elements
		*/
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i+=2) {
            sum += nums[i];
        }
        return sum;
    }
};