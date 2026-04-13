class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // insert everything into hash table
        unordered_set<int> count;   // value
        for (int i = 0; i < nums.size(); i++) {
            count.insert(nums[i]);
        }

        int maxLen = 0; 
        int currentLen = 0;
        int prev = 0xFFFFFFFF;
        for (int num : count) {
            if (count.count(num - 1) == 0) {  // num is a sequence start
                int len = 1;
                while (count.count(num + len)) len++;
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
