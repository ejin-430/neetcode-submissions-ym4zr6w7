class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0; 

        int max_length = 1; 
        int length = 1; 
        int i = 0; 
        int j = 0; 
        unordered_set<char> hash; 
        hash.insert(s[0]); 

        while (j < s.length()-1) {
            if (hash.count(s[j+1]) > 0) {
                hash.erase(s[i]);
                i++; 
                length--; 
            } else {
                j++; 
                hash.insert(s[j]);
                length++;
            }

            if (length > max_length) max_length = length; 
        }
        return max_length; 
    }
};
