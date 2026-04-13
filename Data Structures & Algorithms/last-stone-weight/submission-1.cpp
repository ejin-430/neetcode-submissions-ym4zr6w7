class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0; 

        priority_queue<int> weights;
        for (int i = 0; i < stones.size(); i++) {
            weights.push(stones[i]);
        }

        while (weights.size() > 1) {
            int x = weights.top(); 
            weights.pop();
            int y = weights.top();
            weights.pop();
            if (x != y) {
                y -= x; 
                if (y < 0) y = -y; 
                weights.push(y);
            }
        }

        if (weights.empty()) return 0;
        return weights.top();
    }
};
