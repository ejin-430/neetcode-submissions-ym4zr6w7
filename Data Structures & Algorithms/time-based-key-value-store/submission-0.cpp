class TimeMap {
private: 
    unordered_map <string, vector< pair<int, string>> > m;  // key, <timestamp, value>
public:
    TimeMap() {
        m = {};
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
        return;
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";

        vector<pair<int, string>> v = m[key];
        int lowerBound = 0; 
        int upperBound = v.size()-1; 
        int idx = -1;
        while (lowerBound <= upperBound) {
            int mid = (lowerBound + upperBound) / 2;
            if (v[mid].first == timestamp) {
                idx = mid; 
                break;
            } else if (v[mid].first < timestamp) {
                idx = mid;
                lowerBound = mid+1;
            } else {
                upperBound = mid-1;
            }
        }

        if (idx < 0) return "";
        return v[idx].second;
    }
};