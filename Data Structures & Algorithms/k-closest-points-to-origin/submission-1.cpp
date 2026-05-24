class Solution {
private: 
    int distance(int x, int y) {
        return x*x + y*y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.empty()) return {};

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q = {}; 
        for (int i = 0; i < points.size(); i++) {
            q.push({distance(points[i][0], points[i][1]), i}); 
        }

        vector<vector<int>> result = {}; 
        for (int i = 0; i < k; i++) {
            int idx = q.top().second; 
            q.pop(); 
            result.push_back(points[idx]);
        }
        return result; 
    }
};
