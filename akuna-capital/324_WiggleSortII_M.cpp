class Solution {
public:
    void wiggleSort(vector<int>& nums) {
		// 1. sort the array and partition the array into L and S group based on the midpoint
		// 2. reverse both L and S, and then insert elements in S alternatively in L
		// For example, [1,3,2,2,3,1]
		// after sorting, it becomes [1,1,2,2,3,3]
		// after partition, it becomes [1,1,2] [2,3,3]
		// after reversing both groups, it becomes [2,1,1] [3,3,2]
		// after alternative insertions, it becomes [2,3,1,3,1,2]
		
       vector<int> copy = nums;
        int n = nums.size(), m = (n + 1) / 2;
        sort(copy.begin(), copy.end());
        
        for (int i = m - 1, j = 0; i >= 0; i--, j += 2) nums[j] = copy[i];
        for (int i = n - 1, j = 1; i >= m; i--, j += 2) nums[j] = copy[i];
    }
};