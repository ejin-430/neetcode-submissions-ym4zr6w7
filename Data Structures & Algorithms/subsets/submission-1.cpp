class Solution {
private: 
    vector<vector<int>> result; 
    void backtrack(vector<int>& nums, vector<int>& subset, int idx){
        if (idx >= nums.size()) {
            result.push_back(subset); 
            return;
        }
        subset.push_back(nums[idx]); 
        backtrack(nums, subset, idx+1); 
        subset.pop_back(); 
        backtrack(nums, subset, idx+1); 
        return;
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset; 
        backtrack(nums, subset, 0); 
        return result; 
    }
};
