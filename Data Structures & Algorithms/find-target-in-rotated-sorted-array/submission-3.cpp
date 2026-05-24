class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums[0] == target) return 0; 
        if (nums.back() == target) return nums.size()-1; 

        int i = 0; 
        int j = nums.size() - 1; 

        while (i < j) {
            if (nums[i] == target) return i; 
            if (nums[j] == target) return j; 
            if (j - i == 1) return -1;

            int mid = (i+j)/2; 
            if (nums[mid] == target) return mid;
            else if (nums[i] > nums[mid]) {
                if (nums[mid] < target && target < nums[j]) {
                    i = mid+1; 
                } else {
                    j = mid-1; 
                }
            } else {
                if (nums[i] < target && target < nums[mid]) {
                    j = mid-1; 
                } else {
                    i = mid+1; 
                }
            }
        }

        return -1;
    }
};
