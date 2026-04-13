class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string output = "";
        for (int i = 0; i < strs.size(); i++) {
            string len = to_string(strs[i].length());
            output += len;
            output += '#';
            output += strs[i];
        }
        return output;
    }

    vector<string> decode(string s) {
        if (s.length() == 0) return {};

        vector <string> output = {};
        int i = 0; 
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') j++; 
            int len = stoi(s.substr(i, j - i));
            output.push_back(s.substr(j + 1, len)); 
            i = j + 1 + len; 
        }

        return output;
    }
};
