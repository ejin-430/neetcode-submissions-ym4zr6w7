class Solution {
private: 
    bool result = false; 
    void backtrack(vector<vector<char>>& board, string& word, int row, int col, int idx) {
        if (idx == word.length()) {
            result = true; 
            return;
        }
        // check current cell 
        if (board[row][col] != word[idx]) return;
        char c = board[row][col];
        board[row][col] = '1';
        if (idx + 1 == word.length()) {
            result = true;
            board[row][col] = c;
            return;
        }
        // check all 4 directions
        if (row-1 >= 0 && board[row-1][col] != '1') {
            backtrack(board, word, row-1, col, idx+1);
            if (result) return;
        }
        if (row+1 < board.size() && board[row+1][col] != '1') {
            backtrack(board, word, row+1, col, idx+1);
            if (result) return;
        }
        if (col-1 >= 0 && board[row][col-1] != '1') {
            backtrack(board, word, row, col-1, idx+1);
            if (result) return;
        }
        if (col+1 < board[0].size() && board[row][col+1] != '1') {
            backtrack(board, word, row, col+1, idx+1);
            if (result) return;
        }

        board[row][col] = c;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (!word.empty() && board.empty()) return false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                backtrack(board, word, i, j, 0);
                if (result) return true;
            }
        }

        return false; 
    }
};
