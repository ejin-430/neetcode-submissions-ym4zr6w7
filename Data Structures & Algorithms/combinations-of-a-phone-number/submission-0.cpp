class Solution {
private: 
    vector<vector<char>> letters = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, 
                                    {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, 
                                    {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

    vector<string> result; 
    void backtrack (string& s, string& digits, int start) {
        if (start == digits.size()) {
            result.push_back(s);
            return;
        }

        int digit = digits[start] - '0';
        if (letters[digit].empty()) {
            backtrack(s, digits, start+1);
            return;
        }
        for (int i = 0; i < letters[digit].size(); i++) {
            s.push_back(letters[digit][i]); 
            backtrack(s, digits, start+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;

        string s = {};
        backtrack(s, digits, 0);
        return result;
    }
};
