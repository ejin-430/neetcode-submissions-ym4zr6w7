class Solution {
private: 
    vector<string> result; 
    
    void backtrack(int& n, int open, int close, string& current) {
        if (current.length() == 2*n) {
            result.push_back(current); 
            return;
        }

        if (open < n) {
            current.push_back('(');
            backtrack(n, open+1, close, current);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close+1, current);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n < 0) return {};

        string current = "";
        backtrack(n, 0, 0, current);
        return result;
    }
};
