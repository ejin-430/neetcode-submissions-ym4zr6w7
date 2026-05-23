class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size()); 

        int tmp = 1; 
        for (int i = 0; i < nums.size(); i++) {
            result[i] = tmp; 
            tmp *= nums[i]; 
        }

        tmp = 1; 
        for (int i = nums.size()-1; i >= 0; i--) {
            result[i] *= tmp; 
            tmp *= nums[i]; 
        }

        return result; 
    }
};
