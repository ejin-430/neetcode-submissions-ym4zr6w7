class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false; 

        int hash[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            hash[s1[i]-'a']++;
        }

        int i = 0; 
        for (int j = 0; j < s2.length(); j++) {
            hash[s2[j]-'a']--; 

            while (hash[s2[j]-'a'] < 0) {
                hash[s2[i]-'a']++; 
                i++;
            }

            if (j-i+1 == s1.length()) return true; 
        }
        return false; 
    }
};
