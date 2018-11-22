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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *node = head;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : NULL;
            if (!slow || !fast) {
                return NULL;
            }
            if (slow == fast) {
                break;
            }
        }
        
        while (node != slow) {
            slow = slow->next;
            if (slow == fast) {
                node = node->next;
            }
        }
        return node;
    }
};