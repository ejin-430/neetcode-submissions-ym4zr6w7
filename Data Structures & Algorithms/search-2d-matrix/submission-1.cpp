class Solution {
private: 
    int findRow (vector<vector<int>>& matrix, int target, int lower, int upper) {
        if (lower > upper) return -1;
        int mid = (lower + upper)/2; 
        if (matrix[mid].front() <= target && matrix[mid].back() >= target) return mid; 
        else if (matrix[mid].front() > target) return findRow(matrix, target, lower, mid-1);
        else return findRow(matrix, target, mid+1, upper);
    }

    bool findIndex (vector<int>& row, int target, int lower, int upper) {
        if (lower > upper) return false; 
        int mid = (lower + upper)/2; 
        if (row[mid] == target) return true; 
        else if (row[mid] > target) return findIndex(row, target, lower, mid-1);
        else return findIndex(row, target, mid+1, upper);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int row = findRow(matrix, target, 0, matrix.size()-1); 
        if (row == -1) return false; 
        if (matrix[row][0] == target || matrix[row].back() == target) return true;
        return findIndex(matrix[row], target, 0, matrix[row].size()-1);
    }
};
