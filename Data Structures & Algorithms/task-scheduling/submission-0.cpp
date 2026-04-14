class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // hash everything 
        int hash[26] = {0}; 
        for (int i = 0; i < tasks.size(); i++) {
            int idx = tasks[i] - 'A'; 
            hash[idx]++;
        }

        // put it in a maxheap (count)
        priority_queue<int> heap; 
        for (int i = 0; i < 26; i++) {
            if (hash[i] > 0) {
                heap.push(hash[i]);
            }
        }

        // use queue (count, ready_time) to simulate cooldown 
        queue<pair<int, int>> q; 
        int time = 0; 
        while (!heap.empty() || !q.empty()) {
            if (!q.empty() && q.front().second == time) {
                heap.push(q.front().first);
                q.pop();
            }
            if (!heap.empty()) {
                int top = heap.top() - 1; 
                heap.pop();
                if (top > 0) q.push({top, time+n+1});
            }
            time++;
        }
        return time;
    }
};
