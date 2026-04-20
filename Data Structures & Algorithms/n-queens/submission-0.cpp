class Solution {
private: 
    vector<vector<string>> result = {};

    bool attacked(int n, vector<string>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return 1; 
        }

        int i = row-1; 
        int j = col-1; 
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return 1; 
            i--; 
            j--; 
        }

        i = row-1; 
        j = col+1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') return 1; 
            i--; 
            j++; 
        }
        
        return 0; 
    }

    void backtrack (int& n, vector<string>& current, int i) {
        if (i == n) {
            result.push_back(current); 
            return; 
        }

        for (int j = 0; j < n; j++) {
            if (!attacked(n, current, i, j)) {
                string tmp(n, '.'); 
                tmp[j] = 'Q';
                current.push_back(tmp);
                backtrack(n, current, i+1); 
                current.pop_back();
            } 
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> current = {}; 
        backtrack(n, current, 0);
        return result;
    }
};
