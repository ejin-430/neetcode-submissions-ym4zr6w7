class Solution {
private: 
    int calculateTime(vector<int>& piles, int speed) { 
        int t = 0; 
        for (int i = 0; i < piles.size(); i++) {
            t += (piles[i] + speed - 1) / speed; 
        }
        return t; 
    }

    int searchTime(vector<int>& piles, int h, int min_s, int max_s) {
        if (min_s > max_s) return min_s; 
        
        int mid_s = (min_s + max_s)/2; 
        int time = calculateTime(piles, mid_s);

        if (time <= h) return searchTime(piles, h, min_s, mid_s-1); 
        else return searchTime(piles, h, mid_s+1, max_s);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = 0; 
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > max_pile) max_pile = piles[i]; 
        }

        return searchTime(piles, h, 1, max_pile);
    }
};
