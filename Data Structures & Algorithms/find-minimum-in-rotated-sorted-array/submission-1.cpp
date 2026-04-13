class Solution {
private: 
    int search(vector<int>& n, int start, int end) {
        if (start >= end || n[start] < n[end]) return n[start];
        if (end - start == 1) return min(n[start], n[end]);

        int mid = (start + end)/2;
        if (n[mid] < n[start]) return search(n, start, mid); 
        else return search(n, mid, end);
    }

public:
    int findMin(vector<int> &nums) {
        return search(nums, 0, nums.size()-1);
    }
};
