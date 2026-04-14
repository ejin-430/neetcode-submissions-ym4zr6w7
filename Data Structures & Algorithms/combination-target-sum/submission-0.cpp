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
    void backtrack(vector<int>& nums, int start, vector<int> current, int target, int sum) {
        if (sum == target) result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            sum += nums[i];
            if (sum <= target) backtrack(nums, i, current, target, sum);
            sum -= nums[i];
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if (nums.empty()) return {};

        quicksort(nums, 0, nums.size()-1);
        
        vector<int> current = {};
        backtrack(nums, 0, current, target, 0);

        return result;
    }
};
