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
    int result = 0;

    int maxDepth(TreeNode* node) {
        if (!node) return 0;
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);

        // treat this node as a potential turning point
        result = max(result, left + right); 
        
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return result;
    }
};
