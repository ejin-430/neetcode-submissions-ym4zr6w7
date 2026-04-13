class Solution {
private: 
    int findHour(vector<int>& piles, int h, int minT, int maxT) {
        if (minT > maxT) return minT;

        int totT = 0; 
        int midT = (minT + maxT)/2;
        for (int i = 0; i < piles.size(); i++) {
            totT += (piles[i] + midT - 1) / midT;
        }

        if (totT <= h) return findHour(piles, h, minT, midT-1);
        else return findHour(piles, h, midT+1, maxT);
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0; 
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > maxPile) maxPile = piles[i];
        }

        return findHour(piles, h, 1, maxPile);
    }
};
