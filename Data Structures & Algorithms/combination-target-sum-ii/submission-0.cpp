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
    void backtrack(vector<int>& nums, int start, vector<int>& current, int target, int sum) {
        if (sum == target) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (sum + nums[i] > target) break;
            if (i > start && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            backtrack(nums, i+1, current, target, sum + nums[i]);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};

        quicksort(candidates, 0, candidates.size()-1);
        
        vector<int> current = {};
        backtrack(candidates, 0, current, target, 0);

        return result;
    }
};
