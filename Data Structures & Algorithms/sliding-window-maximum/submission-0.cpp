class Solution {
private: 
    vector<int> q = {};
    
    vector<int> findMax(vector<int>& nums) {
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > max) max = nums[i];
        }
        return {max};
    }

    void enqueue(vector<int>& nums, int element) {
        while (!q.empty() && nums[q.back()] <= nums[element]) {
            q.pop_back();
        }
        q.push_back(element);
        return;
    }

    void dequeue(int element) {
        if (!q.empty() && q[0] == element) q.erase(q.begin());
        return;
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return findMax(nums);
        
        for (int i = 0; i < k; i++) {
            enqueue(nums, i);
        }

        vector<int> sol = {};
        for (int i = k; i < nums.size(); i++) {
            sol.push_back(nums[q[0]]);
            dequeue(i-k);
            enqueue(nums, i);
        }
        sol.push_back(nums[q[0]]);

        return sol;
    }
};
