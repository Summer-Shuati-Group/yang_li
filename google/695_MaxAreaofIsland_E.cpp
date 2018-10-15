class Solution {
public:
    void bfs(vector<vector<int> > &grid, vector<vector<bool> >& visited, int i, int j, int& maxArea) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        } // stopping condition 1: out of border
        else if (grid[i][j] == 0 || visited[i][j] == 1) {
            return;
        } // stopping condition 2: already visited or we have reached the border of the island 
        else if (visited[i][j] == 0) {
            visited[i][j] = 1;	
            if (grid[i][j] == 1) {
                maxArea += 1;
            }
        }
        bfs(grid, visited, i + 1, j, maxArea);
        bfs(grid, visited, i - 1, j, maxArea);
        bfs(grid, visited, i, j + 1, maxArea);
        bfs(grid, visited, i, j - 1, maxArea);
        // bfs 4-directionally 
    }

    int maxAreaOfIsland(vector<vector<int> > &grid)
    {
        int m = grid.size(); 
        int n = grid[0].size();
        // cout << m << " " << n << endl;
        int area = 0;
        int maxArea = 0;
        vector<vector<bool> > visited(m, vector<bool> (n, 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0) {
                    visited[i][j] = 1;
                } 
                else if (visited[i][j] == 0 && grid[i][j] == 1) { // grid[i][j] == 1
                    bfs(grid, visited, i, j, area);
                    maxArea = max(maxArea, area);
                    area = 0;
                }
            }
        }
        return maxArea;
    }
};