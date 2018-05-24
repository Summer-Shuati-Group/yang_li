class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    
    vector<int> twoSum(vector<int>& nums, int target) {

		// 1. Sort, two pointers
		// Time: O(nlog(n) + n + n) = O(nlog(n)) -> sorting + two-pointers-find + locating indices
		// Space: O(n) -> creating a copy vector for locating the indices

        // vector<int> copy = nums;
        // sort(nums.begin(), nums.end());
        // int start = 0;
        // int end = nums.size() - 1;
        // while (nums[start] + nums[end] != target) {
        //     if (nums[start] + nums[end] < target) {
        //         start++;
        //     }
        //     else if (nums[start] + nums[end] > target) {
        //         end--;
        //     }
        // }
        // vector<int> result;
        // for (int i = 0; i < copy.size(); i++) {
        //     if (copy[i] == nums[start]) {
        //         result.push_back(i);
        //     }
        //     else if (copy[i] == nums[end]) {
        //         result.push_back(i);
        //     }
        // }
        // return result;
        

		// 2. Hash (unordered_map) 
		// Time:  O(n + 1) = O(n) -> traverse + find 
		// Space: O(n) -> creating a map storing indices and values of nums vector

        unordered_map<int, int> m;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target-nums[i]) != m.end()) {
                result.push_back(i);
                result.push_back(m.find(target-nums[i])->second);
                sort(result.begin(), result.end());
                return result;
            }
            m[nums[i]] = i;
        }
        
    }
};