class Solution {
private: 
    bool backtrack(vector<vector<char>>& board, string& word, int row, int col, int idx) {
        if (idx == word.length()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;

        // check current cell 
        if (board[row][col] != word[idx]) return false;
        
        // mark current cell as visited
        char c = board[row][col];
        board[row][col] = '1';

        // check all 4 directions
        if (backtrack(board, word, row-1, col, idx+1) ||
            backtrack(board, word, row+1, col, idx+1) ||
            backtrack(board, word, row, col-1, idx+1) ||
            backtrack(board, word, row, col+1, idx+1)) {
            board[row][col] = c;
            return true;
        }

        // update current cell
        board[row][col] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()) return false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }

        return false; 
    }
};
