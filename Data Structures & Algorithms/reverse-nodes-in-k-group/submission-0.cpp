/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // find k-th node
        ListNode * node = head; 
        for (int i = 0; i < k; i++) {
            if (!node) return head;
            node = node->next;

        }
        
        // reverse the section
        ListNode* cur = head; 
        ListNode* prev = nullptr;
        for (int i = 0; i < k; i++) {
            ListNode* tmp = cur->next; 
            cur->next = prev;
            prev = cur;
            cur = tmp; 
        }

        head->next = reverseKGroup(node, k);

        return prev;
    }
};
