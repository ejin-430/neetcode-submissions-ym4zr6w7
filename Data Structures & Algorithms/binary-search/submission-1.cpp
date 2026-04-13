class Solution {
private: 
    int BinarySearch(vector<int>& nums, int target, int start, int end) {
        if (start > end) return -1;

        int mid = (start + end)/2; 
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return BinarySearch(nums, target, start, mid-1);
        else return BinarySearch(nums, target, mid+1, end);
    }
public:
    int search(vector<int>& nums, int target) {
        if (target == nums[0]) return 0;
        if (target == nums.back()) return nums.size()-1;
        
        return BinarySearch(nums, target, 0, nums.size());
    }
};
