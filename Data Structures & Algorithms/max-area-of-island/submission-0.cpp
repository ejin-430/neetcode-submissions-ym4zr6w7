class Solution {
private: 
    int m; 
    int n;
    int dfs(int i, int j, vector<vector<int>>& grid, int area) {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) return 0; 

        grid[i][j] = 0; 
        return 1 + dfs(i-1, j, grid, area) + dfs(i+1, j, grid, area) + dfs(i, j-1, grid, area) + dfs(i, j+1, grid, area);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int max_area = 0; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int area = dfs(i, j, grid, 0);
                    if (area > max_area) max_area = area; 
                }
            }
        }
        return max_area; 
    }
};
