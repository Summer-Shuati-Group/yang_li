class Solution {
public:
    int dac(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int mid = l + (r - l) / 2;
        int lm = dac(nums, l, mid);
        int rm = dac(nums, mid + 1, r);
        if (lm == rm) return lm;
        return (count(nums.begin() + l, nums.begin() + r + 1, lm) > count(nums.begin() + l, nums.begin() + r + 1, rm) ? lm : rm);
    }
    
    int majorityElement(vector<int>& nums) {
        // 1. Hashtable 
		// Time: O(n)
		// Space: O(n) 
        // unordered_map<int, int> m;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (++m[nums[i]] > nums.size() / 2) {
        //         return nums[i];
        //     }
        // }
        
        // 2. Sorting 
		// Time: O(log(n))
        // sort(nums.begin(), nums.end());
        // int mid = nums.size() / 2;
        // return nums[mid];
        
        // 3. Randomization 
		// Time: randomized (fastest among all 5)
        // while (true) {
        //     int count = 0;
        //     int candidate = nums[rand() % nums.size()];
        //     for (int i = 0; i < nums.size(); i++) {
        //         if (nums[i] == candidate) {
        //             count++;
        //         }
        //     }
        //     if (count > nums.size() / 2) return candidate;
        // }
        
        // 4. Divide-and-Conquer
		// Time: O(nlog(n))
        // return dac(nums, 0, nums.size() - 1);
        
        // 5. Moore Voting Algorithm
		// Time: O(n)
        int major = nums[0]; int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                count++;
                major = nums[i];
            }
            else if (major == nums[i]) {
                count++;
            }
            else count--;
        }
        return major;
    }
};