class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		/* Use hash table to check if there is repetitive element */
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;

		/* sort the elements so that duplicates would neighbor
		each other */
		sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};