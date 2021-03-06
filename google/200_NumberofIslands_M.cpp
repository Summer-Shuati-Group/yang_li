class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(); 
        int n = grid[0].size();
        // cout << m << " " << n << endl;
        int cnt = 0;
        vector<vector<bool> > visited(m, vector<bool> (n, 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '0') {
                    visited[i][j] = 1;
                } 
                else if (visited[i][j] == 0 && grid[i][j] == '1') { // grid[i][j] == 1
                    bfs(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
     void bfs(vector<vector<char> > &grid, vector<vector<bool> >& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        } // stopping condition 1: out of border
        else if (grid[i][j] == '0' || visited[i][j] == 1) {
            return;
        } // stopping condition 2: already visited or we have reached the border of the island 
        else if (visited[i][j] == 0) {
            visited[i][j] = 1;	
        }
        bfs(grid, visited, i + 1, j);
        bfs(grid, visited, i - 1, j);
        bfs(grid, visited, i, j + 1);
        bfs(grid, visited, i, j - 1);
        // bfs 4-directionally 
    }
};