class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() <= k) return s.length();

        int count[26] = {};
        int maxLen = 0; 
        int window = 0;
        int i = 0; // start of window
        int maxCount = 0;

        for (int j = 0; j < s.length(); j++) {
            int c = s[j]-'A';
            count[c]++;
            window++;
            if (count[c] > maxCount) maxCount = count[c];

            if (window - maxCount <= k) {
                if (maxLen < window) maxLen = window; 
            } else {
                c = s[i]-'A';
                count[c]--;
                window--;
                i++;
            }
        }

        return maxLen;
    }
};
