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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int count = 0; 
        stack<TreeNode*> nodes;
        stack<int> max_val;
        nodes.push(root);
        max_val.push(root->val);

        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            int maxVal = max_val.top();
            max_val.pop();
            if (node->val >= maxVal) {
                count++;
                maxVal = node->val;
            }

            if (node->left) {
                nodes.push(node->left);
                max_val.push(maxVal);
            }
            if (node->right) {
                nodes.push(node->right);
                max_val.push(maxVal);
            }
        }

        return count;
    }
};
