class Solution {
private: 
    bool isAnagram(const string& str1, const string& str2) {
        if (str1.length() != str2.length()) return false;

        int count[26] = {0};

        for (int i = 0; i < str1.length(); i++) {
            count[str1[i] - 'a']++;
        }

        for (int i = 0; i < str2.length(); i++) {
            count[str2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> sol;
        for (int i = 0; i < strs.size(); i++) {
            vector<string> tmp = {strs[i]};
            for (int j = i+1; j < strs.size(); j++) {
                if (isAnagram(strs[i], strs[j])) {
                    tmp.push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                    j--;
                }
            }
            sol.push_back(tmp);
        }
        return sol;
    }
};
