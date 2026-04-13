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
    int kthSmallest(TreeNode* root, int k) {
        // inorder walk 
        int count = 0;
        stack<TreeNode*> s; 
        TreeNode* cur = root; 
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            } 
            cur = s.top(); 
            s.pop();
            count++;
            if (count == k) break;
            cur = cur->right;
        }

        return cur->val;
    }
};
