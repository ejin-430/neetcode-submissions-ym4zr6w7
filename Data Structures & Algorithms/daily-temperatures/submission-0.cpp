class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> sol (temperatures.size(), 0);
        vector<int> tmpStack = {};

        for (int i = 0; i < temperatures.size(); i++) {
            while (!tmpStack.empty() && temperatures[i] > temperatures[tmpStack.back()]) {
                int idx = tmpStack.back();
                tmpStack.pop_back();
                sol[idx] = i - idx;
            }
            
            tmpStack.push_back(i);
        }

        return sol;
    }
};
