/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return NULL;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (slow && fast) {
            if (fast->val == val) {
                fast = fast->next;
                slow->next = fast;
            } else {
                slow = fast;
                fast = fast->next;
            }
        }
        if (head->val == val) {
            return head = head->next;
        }
        return head;
    }
};