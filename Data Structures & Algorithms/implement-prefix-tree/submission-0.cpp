class TreeNode {
public:
    TreeNode* children[26] = {nullptr};
    bool isEndOfWord = false;
};

class PrefixTree {
private: 
    TreeNode* root; 
public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* current = root; 
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i]-'a'; 
            if (! current->children[idx]) current->children[idx] = new TreeNode();
            current = current->children[idx];
        }
        current->isEndOfWord = true; 
    }
    
    bool search(string word) {
        TreeNode* current = root; 
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i]-'a'; 
            if (! current->children[idx]) return false; 
            current = current->children[idx];
        }
        return current->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* current = root; 
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i]-'a'; 
            if (! current->children[idx]) return false; 
            current = current->children[idx];
        }
        return true;
    }
};
