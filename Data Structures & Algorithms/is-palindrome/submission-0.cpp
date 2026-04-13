class Solution {
private: 
    string normalize(string & s) {
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) str += tolower(s[i]);
        }
        return str;
    }
public:
    bool isPalindrome(string s) {
        s = normalize(s);
        if (s.length() <= 1) return true;

        int i = 0; 
        int j = s.length() - 1;
        while (i < j) {
            cout << s[i] << s[j] << endl;
            if (s[i] != s[j]) return false;
            i++; 
            j--;
        }

        return true;
    }
};
