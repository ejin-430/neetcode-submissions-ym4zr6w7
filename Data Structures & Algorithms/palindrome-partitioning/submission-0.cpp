class Solution {
private: 
    bool isPalindrome (string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false; 
            left++; 
            right--;
        }
        return true; 
    }

    vector<vector<string>> result;
    void backtrack (string& s, int start, vector<string>& current) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                current.push_back(s.substr(start, i-start+1));
                backtrack(s, i+1, current);
                current.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return result;
        vector<string> current = {};
        backtrack(s, 0, current);
        return result;
    }
};
