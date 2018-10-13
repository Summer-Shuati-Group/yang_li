class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0; 
        int j = 0;
        while (i < nums1.size()) {
            if (j >= nums2.size() || nums1[i] < nums2[j]) {
                nums1.erase(nums1.begin() + i);
            } 
			// One case: 
			// if the last number of nums2 is smaller than the current 
			// number of nums1, it means that every number after in nums1 
			// would be larger than the last number of nums2, so that it 
			// is not possible that every number after in nums1 is equal 
			// to the last number of nums2, so that we should remove every 
			// number after in nums1 

			// Other case: 
			// if the current number of nums1 is smaller than the current
			// number of nums2, it means that the current number of nums1 
			// is larger than the previous number of nums2 and smaller than
			// the current number of nums2, so that the current number of 
			// nums1 is not equal to any number in nums2, so that we should
			// remove the current number in nums1

            else if (nums1[i] > nums2[j]) {
                j++;
            }

			// vice versa (on "Other Case" for first if)

            else {
                i++;
                j++;
            }

			// "nums1[i] == nums2[j]": 
			// we should keep the current number of nums1, and advance one
			// step for both nums1 and nums2 to prepare for the next comparison
        }
        return nums1;
    }
};