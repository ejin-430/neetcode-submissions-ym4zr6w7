class Solution {
private: 
    unordered_set<char> hashTable;
    bool isDuplicate (char c) {
        return hashTable.count(c) > 0;
    }
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int maxLen = 1; 
        int currentLen = 1;
        int left = 0; 
        int right = 0; 
        hashTable.insert(s[0]);

        while (right < s.length()-1) {
            if (isDuplicate(s[right+1])) {
                hashTable.erase(s[left]);
                left++;
                currentLen--;
            } else {
                right++;
                currentLen++;
                hashTable.insert(s[right]);
            }

            if (currentLen > maxLen) maxLen = currentLen;
        }

        return maxLen;
    }
};
