class Solution {
private: 
    void quickSort(vector<int>& nums, int start, int end) {
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

        quickSort(nums, start, i-1);
        quickSort(nums, i+1, end);
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol = {};
        int n = nums.size();
        if (n < 2) return sol;
        quickSort(nums, 0, n-1);

        int target = nums[0];
        for (int i = 0; (i < n-2) && (target <= 0); i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1; 
            int k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; 

                if (sum == 0) {
                    sol.push_back({nums[i], nums[j], nums[k]});
                    j++; 
                    k--;
                    while (j < k && nums[j-1] == nums[j]) j++;
                    while (j < k && nums[k+1] == nums[k]) k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return sol;
    }
};
