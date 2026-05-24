class TimeMap {
private: 
    unordered_map <string, vector< pair<int, string> >> hash; // key, <timestamp, value>
public:
    TimeMap() {
        hash = {}; 
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (hash.find(key) == hash.end()) return "";

        vector<pair<int, string>> vec = hash[key];
        int i = 0; 
        int j = vec.size()-1; 
        string result = "";

        while (i <= j) {
            int mid = (i + j)/2; 
            if (vec[mid].first == timestamp) {
                return vec[mid].second;
            } else if (vec[mid].first > timestamp) {
                j = mid-1; 
            } else {
                result = vec[mid].second;
                i = mid+1; 
            }
        }

        return result;
    }
};
