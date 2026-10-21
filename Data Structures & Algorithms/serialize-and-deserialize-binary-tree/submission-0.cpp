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

class Codec {
private: 
    void tree_to_vector(TreeNode* curr, vector<string>& tree_val) {
        if (!curr) {
            tree_val.push_back("null"); 
            return;
        }
        tree_val.push_back(to_string(curr->val)); 
        tree_to_vector(curr->left, tree_val); 
        tree_to_vector(curr->right, tree_val); 
    }

    string encode(vector<string>& tree_val){
        string data; 
        for (int i = 0; i < tree_val.size(); i++){
            data += tree_val[i]; 
            data += ',';
        }
        if (data.size() > 1) data.pop_back(); 
        return data; 
    }
     
    void string_to_vector(string str, vector<string>& tree_val){
        int idx = 0; 
        while (idx < str.size()){
            string val; 
            while(idx < str.size() && str[idx] != ',') {
                val += str[idx]; 
                idx++; 
            }
            tree_val.push_back(val);
            idx++; 
        }
    }

    TreeNode* decode(int& idx, vector<string>& tree_val) {
        if (tree_val[idx] == "null") {
            idx++; 
            return nullptr;
        }
        TreeNode* curr = new TreeNode(stoi(tree_val[idx])); 
        idx++; 
        curr->left = decode(idx, tree_val); 
        curr->right = decode(idx, tree_val);
        return curr; 
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> tree_val;
        tree_to_vector(root, tree_val); 
        return encode(tree_val); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr; 
        vector<string> tree_val;
        string_to_vector(data, tree_val); 
        int idx = 0; 
        return decode(idx, tree_val); 
    }
};
