class Solution {
public:
    bool condition(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || i < 0) {
           return true;    
        }
        else if (j >= grid[0].size() || j < 0) {
            return true;
        }
        else if (grid[i][j] == 0) {
            return true;
        }
        return false;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[0].size(); j++) 
            {
                if (grid[i][j] == 1) 
                {   // count all 4 neighboring locations, 
					// if it's not 1 just add 1 to the perimeter
                    perimeter += condition(grid, i - 1, j) +
                        condition(grid, i, j - 1) + 
                        condition(grid, i + 1, j) + 
                        condition(grid, i, j + 1);
                }
            }
        }
        return perimeter;
    }
};