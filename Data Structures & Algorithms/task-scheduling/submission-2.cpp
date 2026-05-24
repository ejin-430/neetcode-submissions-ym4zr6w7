class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hash[26] = {0};
        for (int i = 0; i < tasks.size(); i++) {
            hash[tasks[i]-'A']++; 
        }

        priority_queue<int> maxheap = {}; 
        for (int i = 0; i < 26; i++) {
            if (hash[i]>0) maxheap.push(hash[i]);
        }

        queue<pair<int, int>> q; //num tasks, next ready time
        int time = 0; 

        while (!maxheap.empty() || !q.empty()) {
            if (!q.empty() && q.front().second == time) {
                maxheap.push(q.front().first);
                q.pop();
            } 
            if (!maxheap.empty()) {
                int task = maxheap.top() - 1; 
                maxheap.pop();
                if (task > 0) q.push({task, time + n + 1});
            }
            time++; 
        }
        return time; 
    }
};
