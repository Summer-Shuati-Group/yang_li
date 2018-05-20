class Solution {
public:
        
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        vector<int> v(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        if (v.size() % 2) {
            result = v[v.size() / 2] + 0.0000;
        }
        else {
            result = (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2.0;
        }
        return result;
    }
};