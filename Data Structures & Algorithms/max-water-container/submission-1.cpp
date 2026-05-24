class Solution {
public:
    int maxArea(vector<int>& heights) {
        if (heights.size() < 1) return 0; 

        int i = 0; 
        int j = heights.size()-1; 
        int max_area = 0; 

        while (i < j) {
            int area = j - i; 
            if (heights[i] < heights[j]) {
                area *= heights[i]; 
                i++; 
            } else {
                area *= heights[j]; 
                j--; 
            }

            if (area > max_area) max_area = area; 
        }

        return max_area; 
    }
};
