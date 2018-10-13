class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		// First Method (create a lookup table): 
        vector<vector<int>> copy = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[j][matrix.size()-1-i] = copy[i][j];
            }
        }
		
		// Second Method: 
		// 1. do the reverse 
		// 2. swap [i][j] and [j][i]
		// for example: 
		/* 
		[1,2,3]    [3,2,1]    [7,4,1]
		[4,5,6] => [6,5,4] => [8,5,2]
		[7,8,9]    [9,8,7]    [9,6,3]
		*/
		reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

		
    }
};