/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> copies;
        queue<Node*> q;
    
        copies[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front(); 
            q.pop(); 
            for (Node* tmp : cur->neighbors) {
                if (copies.find(tmp) == copies.end()) {
                    copies[tmp] = new Node(tmp->val);
                    q.push(tmp);
                }
                copies[cur]->neighbors.push_back(copies[tmp]);
            }
        }

        return copies[node];
    }
};
