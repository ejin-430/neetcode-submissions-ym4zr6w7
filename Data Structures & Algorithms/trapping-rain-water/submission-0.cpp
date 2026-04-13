class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0; 
        int j = height.size()-1;
        int left = 0;
        int right = 0;
        int area = 0;
        
        while (i < j) {
            if (height[i] < height[j]) {
                if (height[i] > left) left = height[i];
                area += (left - height[i]);
                i++; 
            } else {
                if (height[j] > right) right = height[j];
                area += (right - height[j]);
                j--; 
            }
        }

        return area; 
    }
};
