class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = len * (len + 1) / 2;
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return sum;
    }
};