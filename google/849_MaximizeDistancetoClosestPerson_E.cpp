class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int idx = 0;
		// idx: answer for the index
        int last1 = 0;
		// last1: the index for the last 1 in seats
        int first1 = 0;
		// first1: the index for the first 1 in seats
        vector<int> v;
		// v: used to record the distance from the current element to the nearest left 1 in the seats
        int cnt = 0;
		// cnt: counter used to count the index of first 1 
        int count = 0;
		// count: count how many 0s from the last 1
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                cnt++;
                if (cnt == 1) {
                    first1 = i;
                }
                last1 = i;
                count = 0;
                v.push_back(0);
            }
            else {
                count++;
                v.push_back(count);
            }
        }
        idx = count;
        count = 0;
        for (int i = last1; i >= 0; i--) {
            if (seats[i] == 1) {
                count =0;
            }
            else if (i > first1) {
                count++;
                v[i] = min(v[i], count);
                // cout << "v[i]: " << v[i] << endl;
                idx = max(idx, v[i]);
                // cout << "idx: " << idx << endl;
            }
            else {
                count++;
                v[i] = count;
                idx = max(idx, v[i]);
            }
        }
        return idx;
    }
};