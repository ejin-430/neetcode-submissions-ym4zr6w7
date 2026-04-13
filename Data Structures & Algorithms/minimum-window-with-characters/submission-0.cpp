class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> needs;
        int totNeeds = 0;
        
        // set the hash for t to be negative 
        for (int i = 0; i < t.length(); i++) {
            needs[t[i]]++;
            if (needs[t[i]] == 1) totNeeds++;
        }

        int i = 0; 
        int j = 0;
        string sol = "";
        int len = s.length()+1;
        while (j < s.length()) {
            needs[s[j]]--;
            if (needs[s[j]] == 0) totNeeds--;

            while (totNeeds == 0) {
                if (j-i+1 < len) {
                    sol = s.substr(i, j-i+1);
                    len = j-i+1;
                }

                needs[s[i]]++;
                if (needs[s[i]] == 1) totNeeds++;
                i++;
            } 
            
            j++;
        }

        return sol;
    }
};
