class Solution {
private: 
    int count = 0; 
    int m; 
    int n;
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (grid[i][j] == '0') return; 

        grid[i][j] = '0'; 
        if (i > 0) dfs(i-1, j, grid);
        if (i < m-1) dfs(i+1, j, grid);
        if (j > 0) dfs(i, j-1, grid);
        if (j < n-1) dfs(i, j+1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++; 
                    dfs(i, j, grid);
                }
            }
        }
        return count; 
    }
};
