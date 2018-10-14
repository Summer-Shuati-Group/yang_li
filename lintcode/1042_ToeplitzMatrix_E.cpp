class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: True if and only if the matrix is Toeplitz
     */
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        // Write your code here
        int c = matrix.size();
    	int r = matrix[0].size();
    	cout << "c: " << c << endl;
    	cout << "r: " << r << endl;
    	if (c < 2 || r < 2)
    		return true;

		// (1,1), (2,1), (1,2) must be Toeplitz matrix, because there is only one elements in its diagonal 

    	int i = c - 1;
    	int j = 1;
    	// start with the element in the right of bottom-left position 
    	while (i >= 0 && j >= 0)
    	{
    		
    		int val = matrix[i][j];
    		cout << "val: " << val << endl;
			// store the value beforehand so that we can compare later
			
    		int i1 = i;
    		int j1 = j;
			// store the starting point so that we can recover afterwards
			
    		while (j >= 0 && i >= 0) {
    			cout << "matrix[" << i << "][" << j << "]: " << matrix[i][j] << endl;
    			if (val != matrix[i][j]) {
    				return false;
    			}
    			i--;
    			j--;
    		} 
			// check the value in a left-upper diagonal direction
    		
    		i = i1;
    		j = j1;
			// recover the starting point 
    		
    		if (j < r - 1) j++;
    		else i--;
			// proceed to the next starting point 
    	}
    	return true;
    }
};