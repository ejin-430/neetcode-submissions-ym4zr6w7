class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> seenPos = {};
        vector<int> seenNeg = {};
        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i]; 
            int expected = target - val; 
            
            if (expected == nums[0]) return {0, i};

            if (expected > 0 && seenPos.size() > expected && seenPos[expected] != 0) return {seenPos[expected], i};
            else if (expected < 0 && seenNeg.size() > -expected && seenNeg[-expected] != 0) return {seenNeg[-expected], i};

            if (val >= 0) {
                if (seenPos.size() < val+1) seenPos.resize(val+1); 
                seenPos[val] = i;
            } else {
                if (seenNeg.size() < -val+1) seenNeg.resize(-val+1); 
                seenNeg[-val] = i;
            }
        }

        return {0, 0};
    }
};
