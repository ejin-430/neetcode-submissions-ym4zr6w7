/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol = {};
        if (!root) return sol;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level = q.size();
            for (int i = 0; i < level; i++) {
                TreeNode* node = q.front();
                if (i == level-1) sol.push_back(node->val);
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return sol;
    }
};
