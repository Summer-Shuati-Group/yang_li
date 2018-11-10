class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // 2 5 6 10 
        int product = 1;
        int cnt = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            product *= nums[j];
            while (i <= j && product >= k) {
                product /= nums[i];
                i++;
            }
            cnt += j + 1 - i;
        }
        return cnt;
    }
};