class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool horizontal[9][9] = {};
        bool vertical[9][9] = {};
        bool box[9][9] = {};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                // fill in hash 
                // row = i; column = j; box = (i/3)*3 + (j/3)
                int num;
                if (board[i][j] == '.') continue;
                else num = board[i][j] - '1';

                if (horizontal[i][num]) return false;
                else horizontal[i][num] = 1;

                if (vertical[j][num]) return false;
                else vertical[j][num] = 1;

                int boxNum = (i/3)*3 + (j/3);
                if (box[boxNum][num]) return false;
                else box[boxNum][num] = 1;
            }
        }

        return true;
    }
};
