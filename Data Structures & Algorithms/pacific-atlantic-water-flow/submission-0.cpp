class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};

        vector<vector<int>> solution = {};
        int m = heights.size(); 
        int n = heights[0].size();
        queue<pair<int, int>> q = {};

        // Pacific 
        int bit = 0b01; 
        vector<vector<int>> tracker(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            tracker[i][0] |= bit; 
            q.push({i, 0}); 
        }
        for (int j = 1; j < n; j++) {
            tracker[0][j] |= bit; 
            q.push({0, j});
        }
        while (!q.empty()) {
            int cur1 = q.front().first; 
            int cur2 = q.front().second;
            q.pop(); 

            if (cur1 > 0 && !(tracker[cur1-1][cur2] & bit) && heights[cur1-1][cur2] >= heights[cur1][cur2]) {
                tracker[cur1-1][cur2] |= bit; 
                q.push({cur1-1, cur2});
            }
            if (cur2 > 0 && !(tracker[cur1][cur2-1] & bit) && heights[cur1][cur2-1] >= heights[cur1][cur2]) {
                tracker[cur1][cur2-1] |= bit;
                q.push({cur1, cur2-1});
            }
            if (cur1 < m-1 && !(tracker[cur1+1][cur2] & bit) && heights[cur1+1][cur2] >= heights[cur1][cur2]) {
                tracker[cur1+1][cur2] |= bit;
                q.push({cur1+1, cur2});
            }
            if (cur2 < n-1 && !(tracker[cur1][cur2+1] & bit) && heights[cur1][cur2+1] >= heights[cur1][cur2]) {
                tracker[cur1][cur2+1] |= bit;
                q.push({cur1, cur2+1});
            }
        }

        // Atlantic
        bit = 0b10;
        for (int i = 0; i < m; i++) {
            tracker[i][n-1] |= bit; 
            q.push({i, n-1}); 
            if (tracker[i][n-1] == 0b11) solution.push_back({i, n-1});
        }
        for (int j = 0; j < n-1; j++) {
            tracker[m-1][j] |= bit; 
            q.push({m-1, j});
            if (tracker[m-1][j] == 0b11) solution.push_back({m-1, j});
        }
        while (!q.empty()) {
            int cur1 = q.front().first; 
            int cur2 = q.front().second;
            q.pop(); 

            if (cur1 > 0 && !(tracker[cur1-1][cur2] & bit) && heights[cur1-1][cur2] >= heights[cur1][cur2]) {
                tracker[cur1-1][cur2] |= bit; 
                q.push({cur1-1, cur2});
                if (tracker[cur1-1][cur2] == 0b11) solution.push_back({cur1-1, cur2});
            }
            if (cur2 > 0 && !(tracker[cur1][cur2-1] & bit) && heights[cur1][cur2-1] >= heights[cur1][cur2]) {
                tracker[cur1][cur2-1] |= bit;
                q.push({cur1, cur2-1});
                if (tracker[cur1][cur2-1] == 0b11) solution.push_back({cur1, cur2-1});
            }
            if (cur1 < m-1 && !(tracker[cur1+1][cur2] & bit) && heights[cur1+1][cur2] >= heights[cur1][cur2]) {
                tracker[cur1+1][cur2] |= bit;
                q.push({cur1+1, cur2});
                if (tracker[cur1+1][cur2] == 0b11) solution.push_back({cur1+1, cur2});
            }
            if (cur2 < n-1 && !(tracker[cur1][cur2+1] & bit) && heights[cur1][cur2+1] >= heights[cur1][cur2]) {
                tracker[cur1][cur2+1] |= bit;
                q.push({cur1, cur2+1});
                if (tracker[cur1][cur2+1] == 0b11) solution.push_back({cur1, cur2+1});
            }
        }

        return solution;
    }
};
