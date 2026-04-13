class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        // map s into a hash table
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i]-'a';
            arr[idx]++;
        }
        
        // check all elements for t
        for (int i = 0; i < t.length(); i++) {
            int idx = t[i]-'a';
            arr[idx]--;
            if (arr[idx] < 0) return false;
        }

        return true;
    }
};
