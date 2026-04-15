class Solution {
private: 
    void quicksort(vector<int>& nums, int start, int end) {
        if (start >= end) return;
        int pivot = nums[end];
        int i = start; 
        for (int j = start; j < end; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[end]);
        quicksort(nums, start, i-1);
        quicksort(nums, i+1, end);
    }

    vector<vector<int>> result; 

    void backtrack (vector<int> current, int start, vector<int>& nums) {
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            backtrack(current, i+1, nums);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};

        quicksort(nums, 0, nums.size()-1);
        
        vector<int> current = {};
        backtrack(current, 0, nums);

        return result;
    }
};
