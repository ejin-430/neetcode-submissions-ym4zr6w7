class Solution {
private: 
    void quickSort(vector<int>& p, vector<int>& s, int start, int end) {
        if (end <= start) return;

        int pivot = p[end];
        int i = start;
        for (int j = start; j < end; j++) {
            if (p[j] > pivot) {
                swap(p[i], p[j]);
                swap(s[i], s[j]);
                i++;
            } 
        }

        swap(p[i], p[end]);
        swap(s[i], s[end]);

        quickSort(p, s, start, i-1);
        quickSort(p, s, i+1, end);
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // sort everything based on starting position O(nlgn)
        quickSort(position, speed, 0, position.size()-1);

        // calculate time to reach destination O(n)
        // if car[i+1] has shorter time than car[i], it joins the fleet 
        vector<double> time = {};
        for (int i = 0; i < position.size(); i++) {
            double t = (double)(target - position[i])/speed[i];
            if (time.empty() || t > time.back()) time.push_back(t);
        }

        return time.size();
    }
};
