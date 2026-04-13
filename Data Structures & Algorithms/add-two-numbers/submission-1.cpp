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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2; 
        if (!l2) return l1;

        ListNode * cur1 = l1; 
        ListNode * cur2 = l2;
        bool carry = 0;
        while (cur1->next && cur2->next) {
            int sum = cur1->val + cur2->val + carry; 
            if (sum >= 10) {
                sum-=10; 
                carry = 1;
            } else {
                carry = 0;
            }
            cur1->val = sum;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        int sum = cur1->val + cur2->val + carry; 
        if (sum >= 10) {
            sum-=10; 
            carry = 1;
        } else {
            carry = 0;
        }
        cur1->val = sum;

        if (!cur1->next && cur2->next) cur1->next = cur2->next; 
        
        while (carry && cur1->next) {
            cur1 = cur1->next;
            int sum = cur1->val + carry; 
            if (sum >= 10) {
                sum-=10; 
                carry = 1;
            } else {
                carry = 0;
            }
            cur1->val = sum;
            // cur1 = cur1->next;
        }

        if (carry) {
            cur1->next = new ListNode (1);
        }
        return l1;
    }
};
