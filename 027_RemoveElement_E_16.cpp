class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        while (l != nums.size()) {
            if (nums[l] == val) {
                nums.erase(nums.begin() + l);
                l--; // when one element is removed from the array,
				// each element would shift one place backward
				// therefore, we need to set our pointer one place backward
            }
            l++;
        }
        return nums.size();
    }
};