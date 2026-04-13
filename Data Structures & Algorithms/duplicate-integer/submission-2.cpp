class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<bool> seenPos = {};
        vector<bool> seenNeg = {};
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (val >= 0){
                if (seenPos.size() < val + 1) {
                    seenPos.resize(val + 1);
                }
                if (seenPos[val]) {
                    return 1;
                }
                seenPos[val] = 1;
            } else {
                val = -val;
                if (seenNeg.size() < val + 1) {
                    seenNeg.resize(val + 1);
                }
                if (seenNeg[val]) {
                    return 1;
                }
                seenNeg[val] = 1;
            }
        }
        return 0;
    }
};