class Solution {
private: 
    

    int distance(vector<int>& p){
        return (p[0]*p[0] + p[1]*p[1]);     // skipping sqrt calculation to save time
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> sol = {};
        if (points.empty()) return sol;

        // pq stores distance + index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minheap;

        for (int i = 0; i < points.size(); i++) {
            minheap.push({distance(points[i]), i});
        }

        // pop k times
        for (int i = 0; i < k; i++) {
            int idx = minheap.top().second;
            minheap.pop();
            sol.push_back(points[idx]);
        }

        return sol;
    }
};
