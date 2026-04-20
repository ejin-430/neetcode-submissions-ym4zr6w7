class Solution {
private: 
    struct TreeNode{
        TreeNode* children[26] = {nullptr};
        int idx = -1; 
    };
    TreeNode* root; 
    void insert(string& word, int index) {
        TreeNode* current = root; 
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i]-'a'; 
            if (!current->children[idx]) current->children[idx] = new TreeNode();
            current = current->children[idx];
        }
        current->idx = index;
    }

    vector<string> result = {};
    void dfs(TreeNode* node, int i, int j, vector<vector<char>>& board, vector<string>& words) {
        char c = board[i][j]; 
        if (c =='.' || !node->children[c-'a']) return;
        node = node->children[c-'a'];
        if (node->idx > -1) {
            result.push_back(words[node->idx]); 
            node->idx = -1;
        }

        board[i][j] = '.';
        if (i > 0) dfs(node, i-1, j, board, words);
        if (i < board.size()-1) dfs(node, i+1, j, board, words);
        if (j > 0) dfs(node, i, j-1, board, words);
        if (j < board[i].size()-1) dfs(node, i, j+1, board, words);
        board[i][j] = c; 
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TreeNode(); 
        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs(root, i, j, board, words);
            }
        }

        return result; 
    }
};
