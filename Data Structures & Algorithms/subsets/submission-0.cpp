class Solution {
private: 
    vector<vector<int>> result; 

    void backtrack (int start, vector<int> current, vector<int>& nums) {
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i+1, current, nums);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current = {};
        backtrack(0, current, nums);
        return result;
    }
};
