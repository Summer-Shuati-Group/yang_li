class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows == 0) return v;
        vector<int> v1;
        v1.push_back(1);
        v.push_back(v1);
        if (numRows == 1) return v;
        else {
            int i = 1;
            while (i != numRows) {
                vector<int> temp;
                temp.push_back(1);
                for (int j = 0; j < v[i-1].size() - 1; j++) {
                    temp.push_back(v[i-1][j] + v[i-1][j+1]);
                }
                temp.push_back(1);
                v.push_back(temp);
                i++;
            }
            return v;
        }
    }
};