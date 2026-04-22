class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size(); 
        int n = board[0].size(); 
        queue<vector<int>> q = {};
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '#'; 
                q.push({i, 0});
            }
            if (board[i][n-1] == 'O') {
                board[i][n-1] = '#'; 
                q.push({i, n-1});
            }
        }
        for (int i = 1; i < n-1; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = '#'; 
                q.push({0, i});
            }
            if (board[m-1][i] == 'O') {
                board[m-1][i] = '#'; 
                q.push({m-1, i});
            }
        }

        while (!q.empty()) {
            int x = q.front()[0]; 
            int y = q.front()[1];
            q.pop(); 

            if (x>0 && board[x-1][y]=='O') {
                board[x-1][y] = '#';
                q.push({x-1, y});
            }
            if (x<m-1 && board[x+1][y]=='O') {
                board[x+1][y] = '#';
                q.push({x+1, y});
            }
            if (y>0 && board[x][y-1]=='O') {
                board[x][y-1] = '#';
                q.push({x, y-1});
            }
            if (y<n-1 && board[x][y+1]=='O') {
                board[x][y+1] = '#';
                q.push({x, y+1});
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }

        return;
    }
};
