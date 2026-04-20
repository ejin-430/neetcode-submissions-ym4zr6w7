class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;

        queue<pair<int, int>> q;

        int m = grid.size(); 
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) q.push({i, j});
            }
        }

        while (!q.empty()) {
            int cur1 = q.front().first; 
            int cur2 = q.front().second;
            q.pop(); 

            // top 
            if (cur1 > 0 && grid[cur1-1][cur2] > grid[cur1][cur2]+1) {
                grid[cur1-1][cur2] = grid[cur1][cur2]+1;
                q.push({cur1-1, cur2});
            }
            // down 
            if (cur2 > 0 && grid[cur1][cur2-1] > grid[cur1][cur2]+1) {
                grid[cur1][cur2-1] = grid[cur1][cur2]+1;
                q.push({cur1, cur2-1});
            }
            // left 
            if (cur1 < m-1 && grid[cur1+1][cur2] > grid[cur1][cur2]+1) {
                grid[cur1+1][cur2] = grid[cur1][cur2]+1;
                q.push({cur1+1, cur2});
            }
            // right
            if (cur2 < n-1 && grid[cur1][cur2+1] > grid[cur1][cur2]+1) {
                grid[cur1][cur2+1] = grid[cur1][cur2]+1;
                q.push({cur1, cur2+1});
            }
        }

        return;
    }
};
