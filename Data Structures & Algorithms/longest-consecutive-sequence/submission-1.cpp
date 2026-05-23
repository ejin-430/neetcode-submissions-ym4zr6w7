class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> hash; 
        for (int i = 0; i < nums.size(); i++) {
            hash.insert(nums[i]); 
        }

        int max_length = 0; 
        for (int entry:hash) {
            if (!hash.count(entry-1)) {
                int len = 1; 
                while (hash.count(entry+len)) len++; 
                if (len > max_length) max_length = len; 
            }
        }

        return max_length; 
    }
};
