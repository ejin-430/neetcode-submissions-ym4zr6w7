class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // minheap with k elements 
        priority_queue<int, vector<int>, greater<int>> minheap = {}; 
        for (int i = 0; i < nums.size(); i++) {
            minheap.push(nums[i]); 
            if (minheap.size() > k) minheap.pop();
        }
        return minheap.top(); 
    }
};
