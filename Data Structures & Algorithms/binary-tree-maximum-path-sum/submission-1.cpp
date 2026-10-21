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

    int dfs(TreeNode* curr) {
        if (!curr) return 0;
        int left = std::max(0, dfs(curr->left)); 
        int right = std::max(0, dfs(curr->right)); 
        int path = curr->val + left + right; 
        if (path > result) result = path; 
        
        int max_child = std::max(left, right); 
        return curr->val + max_child; 
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root) {
            result = root->val; 
            dfs(root); 
        }
        return result; 
    }
};
