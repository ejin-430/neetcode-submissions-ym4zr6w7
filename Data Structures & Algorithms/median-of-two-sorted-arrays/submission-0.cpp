class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // nums1 is the shorter list
        if (nums1.size() > nums2.size()) {
            vector<int> tmp = nums1;
            nums1 = nums2; 
            nums2 = tmp;
        }
        int len1 = nums1.size(); 
        int len2 = nums2.size();
        int median_pos = (len1 + len2 + 1)/2; 

        int i = 0; 
        int j = len1; 
        while (i <= j) {
            int mid = (i+j)/2;

            // comparison values from nums1
            double left1;
            double right1;
            if (mid > 0) left1 = nums1[mid - 1];
            else left1 = -1e9;
            if (mid < len1) right1 = nums1[mid];
            else right1 = 1e9;
            // comparison values from nums2
            double left2 = nums2[median_pos-mid-1];
            double right2 = nums2[median_pos-mid];

            // is everything from nums1's left < nums2's right? 
            // is everything from nums2's left < nums1's right? 
            if (left1 <= right2 && left2 <= right1) {
                if ((len1+len2)%2) {    // odd size
                    return max(left1, left2);
                } else {                // even size
                    return (max(left1, left2) + min(right1, right2))/2;
                }
            } else if (left1 > right2) {    // we took too much from nums1
                j = mid-1;
            } else {                        // we took too much from nums2
                i = mid + 1;
            }
        }
        return 0.0;
    }
};
