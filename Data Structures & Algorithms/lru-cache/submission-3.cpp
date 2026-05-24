class LRUCache {
private: 
    int cap; 
    struct ListNode {
        int key; 
        int val; 
        ListNode* next; 
        ListNode* prev; 
        ListNode() : key(0), val(0), next(nullptr), prev(nullptr){}
        ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr){}
        ListNode(int key, int val, ListNode* next) : key(key), val(val), next(next), prev(nullptr){}
        ListNode(int key, int val, ListNode* next, ListNode* prev) : key(key), val(val), next(next), prev(prev){}
    };

    unordered_map <int, ListNode*> key_to_node; 
    ListNode * head; 
    ListNode * tail; 

    void insert_head(ListNode * node) {
        node->prev = head; 
        head->next->prev = node; 
        node->next = head->next; 
        head->next = node; 
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
            // shift node to head 
            node->prev->next = node->next; 
            node->next->prev = node->prev; 
            insert_head(node);
            return node->val;
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (key_to_node.count(key)) {
            ListNode* node = key_to_node[key];
            node->val = value;
            // shift node to head 
            node->prev->next = node->next; 
            node->next->prev = node->prev; 
            insert_head(node);
        } else {
            if (key_to_node.size() == cap) {
                ListNode * to_del = tail->prev; 
                to_del->prev->next = tail; 
                tail->prev = to_del->prev;
                key_to_node.erase(to_del->key); 
                delete to_del; 
            }
            ListNode * node = new ListNode(key, value);
            key_to_node.insert({key, node});
            insert_head(node); 
        }
    }
};
