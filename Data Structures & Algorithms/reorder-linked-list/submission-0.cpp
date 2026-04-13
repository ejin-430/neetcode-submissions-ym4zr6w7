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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // find middle 
        ListNode * slow = head; 
        ListNode * fast = head; 
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        slow->next = nullptr;

        // reverse second half 
        ListNode* cur = second;  // start from second, not slow
        ListNode* prev = nullptr;       // the head of the second half
        while (cur != nullptr) {
            ListNode* tmp = cur->next; 
            cur->next = prev;
            prev = cur;
            cur = tmp; 
        }

        // merge the 2 halves
        ListNode* cur1 = head; 
        ListNode* cur2 = prev;
        while (cur1->next != nullptr && cur2 != nullptr) {
            ListNode * tmp = cur2->next;
            cur2->next = cur1->next;
            cur1->next = cur2;
            cur1 = cur2->next;
            cur2 = tmp;
        }

        return;
    }
};
