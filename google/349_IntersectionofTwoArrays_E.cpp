class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.empty() || nums2.empty()) return ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> s;
        int i = 0;
        int j = 0;
        while (i != nums1.size() && j != nums2.size()) {
            if (nums1[i] > nums2[j]) {
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                s.insert(nums1[i]);
                i++;
                j++;
            }
        }
        for (auto it = s.begin(); it != s.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};