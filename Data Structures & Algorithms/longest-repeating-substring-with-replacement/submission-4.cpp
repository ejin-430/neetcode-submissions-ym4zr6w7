class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() <= k) return s.length(); 

        int max_length = 1; 
        int length = 0; 
        int count = 0; 
        int i = 0; 
        int j = 0; 
        int hash[26] = {0}; 

        while (j < s.length()) {
            hash[s[j] - 'A']++;
            length++;
            if (hash[s[j] - 'A'] > count) count = hash[s[j] - 'A']; 

            if (length - count > k) {
                hash[s[i] - 'A']--; 
                length--; 
                i++; 
            } else {
                if (length > max_length) max_length = length; 
            }
            j++;
        }
        return max_length;
    }
};
