class MedianFinder {
private: 
    priority_queue<int, vector<int>, greater<int>> minH; // for the larger half
    priority_queue<int> maxH; // for the smaller half
public:
    MedianFinder() {
        minH = {}; 
        maxH = {}; 
    }
    
    void addNum(int num) {
        if (minH.empty() || num <= minH.top()) maxH.push(num); 
        else minH.push(num); 

        while (minH.size() > maxH.size() + 1) {
            maxH.push(minH.top()); 
            minH.pop();
        }

        while (maxH.size() > minH.size() + 1) {
            minH.push(maxH.top()); 
            maxH.pop();
        }
    }
    
    double findMedian() {
        if (minH.size() == maxH.size()) return (minH.top() + maxH.top())/2.0;
        else if (minH.size() > maxH.size()) return minH.top(); 
        else return maxH.top();
    }
};
