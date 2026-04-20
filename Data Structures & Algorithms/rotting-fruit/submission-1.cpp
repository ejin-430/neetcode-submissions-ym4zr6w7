class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        queue<pair<int, int>> q;

        int m = grid.size(); 
        int n = grid[0].size();
        int fresh = 0; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++; 
                } 
            }
        }
        if (!fresh) return 0; 

        int time = 0; 
        while (!q.empty() && fresh > 0) {
            int q_size = q.size(); 
            for (int i = 0; i < q_size; i++) {
                int cur1 = q.front().first; 
                int cur2 = q.front().second;
                q.pop(); 

                // top 
                if (cur1 > 0 && grid[cur1-1][cur2] == 1) {
                    grid[cur1-1][cur2] = 2;
                    fresh--;
                    q.push({cur1-1, cur2});
                }
                // down 
                if (cur2 > 0 && grid[cur1][cur2-1] == 1) {
                    grid[cur1][cur2-1] = 2;
                    fresh--;
                    q.push({cur1, cur2-1});
                }
                // left 
                if (cur1 < m-1 && grid[cur1+1][cur2] == 1) {
                    grid[cur1+1][cur2] = 2;
                    fresh--;
                    q.push({cur1+1, cur2});
                }
                // right
                if (cur2 < n-1 && grid[cur1][cur2+1] == 1) {
                    grid[cur1][cur2+1] = 2;
                    fresh--;
                    q.push({cur1, cur2+1});
                }
            }
            time++; 
        }
        
        if (fresh > 0) return -1; 
        return time; 
    }
};
