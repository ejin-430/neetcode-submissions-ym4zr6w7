class KthLargest {
private: 
    int cap; 
    priority_queue<int, vector<int>, greater<int>> minheap; // data type, underlying container, comparison method

public:
    KthLargest(int k, vector<int>& nums) {
        cap = k; 
        for (int i = 0; i < nums.size(); i++) {
            minheap.push(nums[i]);
            if (minheap.size() > cap) minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if (minheap.size() > cap) minheap.pop();
        return minheap.top();
    }
};
