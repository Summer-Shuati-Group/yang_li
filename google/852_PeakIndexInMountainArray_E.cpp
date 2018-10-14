class Solution {
public:
    int binarySearch(vector<int> v, int l, int r) 
	{
        if (r - l <= 1) {
            return (v[r] > v[l] ? r : l);
        }
        int mid = l + (r - l) / 2;
        if (v[mid + 1] > v[mid]) {
            return binarySearch(v, mid + 1, r);
        }
        else {
            return binarySearch(v, l, mid);
        }
    }

    int peakIndexInMountainArray(vector<int> &A)
    {
        return binarySearch(A, 0, A.size() - 1);
    }
};