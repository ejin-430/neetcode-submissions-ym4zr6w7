class Solution {
private: 
    vector<vector<int>> result; 

    void backtrack (vector<int> current, vector<int>& nums, vector<bool>& visited) {
        if (current.size() == nums.size()) result.push_back(current);

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue; 
            current.push_back(nums[i]);
            visited[i] = 1; 
            backtrack(current, nums, visited);
            visited[i] = 0; 
            current.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        
        vector<int> current = {};
        vector<bool> visited(nums.size(), false); 
        backtrack(current, nums, visited);

        return result;
    }
};
