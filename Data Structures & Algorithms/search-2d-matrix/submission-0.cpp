class Solution {
private: 
    int searchRows(vector<vector<int>>& m, int target, int start, int end) {
        if (start > end) return -1;

        int mid = (start + end)/2; 
        if (m[mid].front() <= target && m[mid].back() >= target) return mid;
        else if (m[mid].front() > target) return searchRows(m, target, start, mid-1);
        else return searchRows(m, target, mid+1, end);
    }

    bool binarySearch(vector<int>& nums, int target, int start, int end) {
        if (start > end) return false;

        int mid = (start + end)/2; 
        if (nums[mid] == target) return true;
        else if (nums[mid] > target) return binarySearch(nums, target, start, mid-1);
        else return binarySearch(nums, target, mid+1, end);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // search the rows first to target the row
        int row = searchRows(matrix, target, 0, matrix.size()-1); 
        if (row == -1) return false;

        // search the rows 
        if (target == matrix[row][0] || target == matrix[row].back()) return true;
        return binarySearch(matrix[row], target, 0, matrix[row].size()-1);
    }
};
