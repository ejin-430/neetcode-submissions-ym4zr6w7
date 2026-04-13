class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0; 
        int j = heights.size() - 1;
        int maxArea = -1;
        
        while (i<j) {
            int area = j-i;
            if (heights[i] <= heights[j]) {
                area *= heights[i]; 
                i++;
            } else {
                area *= heights[j]; 
                j--;
            }
            if (area > maxArea) maxArea = area;
        }

        return maxArea;
    }
};
