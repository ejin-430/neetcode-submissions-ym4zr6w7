class Solution {
private: 
    bool isOperation(string s) {
        return (s == "+" || s == "-" || 
                s == "*" || s == "/");
    }
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums; 

        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            
            if (!isOperation(s)) {
                nums.push_back(stoi(s));
            } else if (nums.size() > 1) {
                int a = nums.back(); 
                nums.pop_back(); 
                int b = nums.back();
                nums.pop_back(); 

                if (s == "+") {
                    nums.push_back(b+a);
                } else if (s == "-") {
                    nums.push_back(b-a);
                } else if (s == "*") {
                    nums.push_back(b*a);
                } else if (s == "/") {
                    nums.push_back(b/a);
                }
            }
        }
        return nums.back();
    }
};
