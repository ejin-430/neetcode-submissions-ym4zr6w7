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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr; 

        TreeNode * root = new TreeNode(preorder[0]);
        // Search for root within the inorder array 
        int idx = 0; 
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                idx = i; 
                break;
            }
        }

        // Recursively place the children
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + idx);
        vector<int> rightPreorder(preorder.begin() + 1 + idx, preorder.end());

        vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
        vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root; 
    }
};
