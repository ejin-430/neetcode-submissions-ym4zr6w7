class Solution {
private: 
    int count[26] = {0};

public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(); 
        int len2 = s2.length();

        if (len1 > len2) return false;

        for (int i = 0; i < len1; i++) {
            count[s1[i] - 'a']++;
        }

        int i = 0;
        for (int j = 0; j < len2; j++) {
            int c = s2[j]-'a';
            count[c]--;

            while (count[c] < 0) {
                int idx = s2[i]-'a';
                count[idx]++;
                i++;
            }

            if (j-i+1 == len1) return true;
        }
        return false;
    }
};
