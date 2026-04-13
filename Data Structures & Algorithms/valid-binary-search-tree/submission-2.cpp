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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        // inorder walk 
        vector<int> values = {};
        stack<TreeNode*> s; 
        TreeNode* cur = root; 
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            } 
            cur = s.top(); 
            s.pop();
            values.push_back(cur->val);
            cur = cur->right;
        }

        // verify 
        for (int i = 1; i < values.size(); i++) {
            if (values[i] <= values[i-1]) return false;
        }

        return true;
    }
};
