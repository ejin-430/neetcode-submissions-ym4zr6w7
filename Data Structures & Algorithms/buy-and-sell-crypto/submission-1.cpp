class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int highest = 0;
        int maxGain = 0;

        for (int i = prices.size()-1; i >= 0; i--) {
            if (prices[i] > highest) highest = prices[i]; 
            prices[i] = highest - prices[i]; 
            if (prices[i] > maxGain) maxGain = prices[i];
        }

        return maxGain;
    }
};
