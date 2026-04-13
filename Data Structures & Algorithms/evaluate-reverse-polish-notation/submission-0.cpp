class Solution {
private: 
    vector<int> nums = {};

    bool isOperations(string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
public:
    int evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if (!isOperations(s)) {
                nums.push_back(stoi(s));
            } else if (nums.size() > 1) {
                int b = nums.back();
                nums.pop_back();
                int a = nums.back();
                nums.pop_back();

                if (s == "+") {
                    nums.push_back(a+b);
                } else if (s == "-") {
                    nums.push_back(a-b);
                } else if (s == "*") {
                    nums.push_back(a*b);
                } else if (s == "/") {
                    nums.push_back(a/b);
                }
            } 
        }

        return nums.back();
    }
};
