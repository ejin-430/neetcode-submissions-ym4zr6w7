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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode * cur1 = list1;
        ListNode * cur2 = list2; 
        ListNode * head = list1; 

        if (cur1->val > cur2->val) {
            head = list2; 
            ListNode * tmp = cur1; 
            cur1 = cur2; 
            cur2 = tmp;
        }

        while (cur1->next != nullptr && cur2 != nullptr) {
            if (cur2->val >= cur1->val && cur2->val < cur1->next->val) {
                ListNode * tmp = cur2->next;
                cur2->next = cur1->next;
                cur1->next = cur2;
                cur2 = tmp;
            } else {
                cur1 = cur1->next;
            }
        }

        if (cur1->next == nullptr && cur2 != nullptr) {
            cur1->next = cur2;
        }

        return head;
    }

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr; 
        if (lists.size() == 1) return lists[1];
        ListNode* list1 = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            ListNode* list2 = lists[i];
            list1 = mergeTwoLists(list1, list2);
        }

        return list1;
    }
};
