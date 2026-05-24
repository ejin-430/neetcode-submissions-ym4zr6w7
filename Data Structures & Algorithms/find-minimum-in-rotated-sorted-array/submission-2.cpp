class Solution {

public:
    int findMin(vector<int> &nums) {
        int i = 0; 
        int j = nums.size() - 1; 

        while (i < j && nums[i] > nums[j]) {
            if (j - i == 1) return min(nums[i], nums[j]);

            int mid = (i+j)/2; 
            if (nums[i] > nums[mid]) j = mid; 
            else i = mid; 
        }

        return nums[i];
    }
};
