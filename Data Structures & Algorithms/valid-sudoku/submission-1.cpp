class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9]; 
        bool cols[9][9]; 
        bool boxes[9][9]; 

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue; 

                int val = board[i][j] - '1';
                if (rows[i][val]) return false; 
                rows[i][val] = true; 

                if (cols[j][val]) return false; 
                cols[j][val] = true; 

                if (boxes[(i/3)*3 + (j/3)][val]) return false; 
                boxes[(i/3)*3 + (j/3)][val] = true; 
            }
        }

        return true; 
    }
};
