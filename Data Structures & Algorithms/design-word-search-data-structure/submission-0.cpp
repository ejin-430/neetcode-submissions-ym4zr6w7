class TreeNode {
public:
    TreeNode* children[26] = {nullptr};
    bool isEndOfWord = false;
};

class WordDictionary {
private: 
    TreeNode* root;

    bool dfs(TreeNode* node, int idx, string& word) {
        if (!node) return false; 
        if (idx == word.length()) return node->isEndOfWord;

        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(node->children[i], idx+1, word)) return true;
            }
            return false;
        } else {
            int i = word[idx]-'a';
            return dfs(node->children[i], idx+1, word);
        }
    }
public:
    WordDictionary() {
        root = new TreeNode(); 
    }
    
    void addWord(string word) {
        TreeNode* current = root; 
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i]-'a'; 
            if (!current->children[idx]) current->children[idx] = new TreeNode();
            current = current->children[idx];
        }
        current->isEndOfWord = true; 
    }
    
    bool search(string word) {
        return dfs(root, 0, word);
    }
};
