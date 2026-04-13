class LRUCache {
private: 
    // Definition for doubly-linked list.
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
        ListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
        ListNode(int x, int y, ListNode *next) : key(x), val(y), next(next), prev(nullptr) {}
        ListNode(int x, int y, ListNode *next, ListNode *prev) : key(x), val(y), next(next), prev(prev) {}
    };

    unordered_map <int, ListNode*> key_to_node;
    int cap;
    ListNode* head;
    ListNode* tail;

    void insert_to_front(ListNode * node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(); 
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (key_to_node.count(key)) {
            ListNode* node = key_to_node[key]; 
            node->prev->next = node->next;
            node->next->prev = node->prev;
            insert_to_front(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (get(key) == -1) {
            // insert a new node
            if (key_to_node.size() == cap) {
                // cache size check
                ListNode* tmp = tail->prev;
                key_to_node.erase(tmp->key);
                tmp->prev->next = tail;
                tail->prev = tmp->prev;
                delete tmp;
            }
            ListNode * node = new ListNode(key, value);
            // update cache warmth
            insert_to_front(node);
            key_to_node.insert({key, node});
        } else {
            // update existing node
            ListNode* node = key_to_node[key]; 
            node->val = value; 
            node->prev->next = node->next;
            node->next->prev = node->prev;
            insert_to_front(node);
        }
    }
};
