class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {}; 
        if (nums.size() < 3) return result; 

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i+1; 
            int k = nums.size() - 1; 

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; 
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++; 
                    k--; 
                    while (j<k && nums[j-1] == nums[j]) j++; 
                    while (j<k && nums[k+1] == nums[k]) k--; 
                } else if (sum < 0) {
                    j++; 
                } else {
                    k--;
                }
            }
        }

        return result; 
    }
};
