class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> ans;
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < S.length(); i++) {
            if (sum + widths[S[i] - 'a'] > 100) {
                cnt++;
                sum = widths[S[i] - 'a'];
            }
            else {
                sum += widths[S[i] - 'a'];
            } 
            // cout << "i: " << i << " sum: " << sum << endl;
        }
        ans.push_back(cnt);
        ans.push_back(sum);
        return ans;
    }
};