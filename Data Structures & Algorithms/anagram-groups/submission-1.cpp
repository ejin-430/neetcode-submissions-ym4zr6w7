class Solution {
private: 
    vector<vector<string>> result; 
    bool isAnagram (string str1, string str2) {
        if (str1.length() != str2.length()) return false; 

        int hash[26] = {0};
        for (int i = 0; i < str1.length(); i++) {
            hash[str1[i]-'a']++; 
            hash[str2[i]-'a']--; 
        }

        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) return false; 
        }
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return result; 

        for (int i = 0; i < strs.size(); i++) {
            vector<string> cur = {strs[i]};
            for (int j = i+1; j < strs.size(); j++) {
                if (isAnagram(strs[i], strs[j])) {
                    cur.push_back(strs[j]); 
                    strs.erase(strs.begin() + j); 
                    j--;
                }
            }
            result.push_back(cur); 
        }
        return result; 
    }
};
