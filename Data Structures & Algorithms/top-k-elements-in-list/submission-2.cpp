class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> hash; // val, freq
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++; 
        }

        vector<vector<int>> sort (nums.size() + 1); // init enough entries
        for (auto& entry:hash) {
            sort[nums.size()-entry.second].push_back(entry.first);
        }

        vector<int> result; 
        for (int i = 0; i < sort.size(); i++) {
            for (int j = 0; j < sort[i].size(); j++) {
                result.push_back(sort[i][j]);
                if (result.size() == k) return result;
            }
        }

        return result; 
    }
};
