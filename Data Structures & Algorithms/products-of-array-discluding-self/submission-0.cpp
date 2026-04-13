class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol (nums.size()); 

        int tmp = 1;
        for (int i = 0; i < nums.size(); i++) {
            sol[i] = tmp;
            tmp *= nums[i];
        }

        tmp = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            sol[i] *= tmp;
            tmp *= nums[i];
        }

        return sol;
    }
};
