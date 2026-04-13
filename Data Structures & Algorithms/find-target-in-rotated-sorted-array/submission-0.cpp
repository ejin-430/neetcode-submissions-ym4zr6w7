class Solution {
private: 
    int binarySearch(vector<int>& n, int target, int start, int end) {
        if (start > end) return -1;

        int mid = (start + end)/2;
        if (n[mid] == target) return mid;

        // Left half is sorted
        if (n[start] <= n[mid]) {
            if (target >= n[start] && target < n[mid])
                return binarySearch(n, target, start, mid - 1);
            else
                return binarySearch(n, target, mid + 1, end);
        }
        // Right half is sorted
        else {
            if (target > n[mid] && target <= n[end])
                return binarySearch(n, target, mid + 1, end);
            else
                return binarySearch(n, target, start, mid - 1);
        }
    }

public:
    int search(vector<int>& nums, int target) {
        if (nums[0] == target) return 0;
        if (nums.back() == target) return nums.size()-1;

        return binarySearch(nums, target, 0, nums.size()-1);
    }
};
