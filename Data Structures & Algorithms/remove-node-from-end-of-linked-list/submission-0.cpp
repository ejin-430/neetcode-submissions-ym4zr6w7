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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * prev = nullptr;
        ListNode * toRemove = head;
        ListNode * findTail = head;
        for (int i = 0; i < n; i++) {
            findTail = findTail->next;
        }

        while (findTail != nullptr) {
            prev = toRemove;
            toRemove = toRemove->next;
            findTail = findTail->next;
        }

        if (n == 0) {
            prev->next = toRemove->next;
        } else if (toRemove == head) {
            head = head->next;
            toRemove->next = nullptr;
        } else {
            prev->next = toRemove->next;
            toRemove->next = nullptr;
        }

        return head;
    }
};
