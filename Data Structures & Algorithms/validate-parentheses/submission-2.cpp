class Solution {
private: 
    bool isOpen(char c) {
        return ((c == '(') || (c == '[') || (c == '{'));
    }

    bool match(char open, char closed) {
        return ((open == '(' && closed == ')') ||
                (open == '[' && closed == ']') ||
                (open == '{' && closed == '}'));
    }
public:
    bool isValid(string s) {
        vector<char> openBrackets = {};
        for (int i = 0; i < s.length(); i++) {
            if (isOpen(s[i])) {
                openBrackets.push_back(s[i]);
            } else if (!openBrackets.empty() && match(openBrackets.back(), s[i])) {
                openBrackets.pop_back();
            } else {
                return false;
            }
        }
        
        if (openBrackets.empty()) return true;
        else return false;
    }
};
