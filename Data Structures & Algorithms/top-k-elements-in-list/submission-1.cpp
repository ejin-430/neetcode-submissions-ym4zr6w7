class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;   // value, frequency
        int len = nums.size();
        vector<vector<int>> buckets (len);
        
        for (int i = 0; i < len; i++) {
            count[nums[i]]++;
        }

        for (auto& entry : count) {
            buckets[len - entry.second].push_back(entry.first);
        }

        vector<int> sol; 
        for (int i = 0; i < len; i++) {
            if (sol.size() == k) break;
            for (int j = 0; j < buckets[i].size(); j++) {
                sol.push_back(buckets[i][j]);
            }
        }
        return sol;
    }
};
