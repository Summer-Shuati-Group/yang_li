class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end) {
        if (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
                return mid;
            }
            if (nums[mid-1] > nums[mid]) {
                return binarySearch(nums, start, mid - 1);
            } // if there is an element in the left, then there must be a peak in the left 
            else {
                return binarySearch(nums, mid + 1, end);
            }
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        else if (nums[0] > nums[1]) return 0;
        else if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        else return binarySearch(nums, 0, nums.size() - 1);
    }
};