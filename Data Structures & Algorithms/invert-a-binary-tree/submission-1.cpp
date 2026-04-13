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
private: 
    void invert(TreeNode * node) {
        // if (!node || (!node->left && !node->right)) return;
        TreeNode * tmp = node->right; 
        node->right = node->left; 
        node->left = tmp; 
        if (node->left) invert(node->left); 
        if (node->right) invert(node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) invert(root);
        return root;
    }
};
