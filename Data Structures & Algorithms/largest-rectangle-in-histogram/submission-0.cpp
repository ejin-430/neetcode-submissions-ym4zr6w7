class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<int> s = {};

        for (int i = 0; i <= heights.size(); i++) {
            int h;
            if (i == heights.size()) h = 0;
            else h = heights[i];

            while (!s.empty() && h < heights[s.back()]) {
                int idx = s.back();
                s.pop_back();

                int area = 0;
                if (s.empty()) area = heights[idx] * i;
                else area = heights[idx] * (i - s.back() - 1);

                if (area > maxArea) maxArea = area;
            }
            s.push_back(i);
        }

        return maxArea;
    }
};
