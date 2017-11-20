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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* nl2) {
        ListNode *head = NULL;
        ListNode *temp = NULL;
        int high(0);
        while (l1 != NULL || l2 != NULL) {
            int val1(0),val2(0);
            if (l1) {
                val1 = l1->val;
            }
            if (l2) {
                val2 = l2->val;
            }
            int t = val1 + val2 + high;
            high = t / 10;
            int val = t % 10;
            ListNode *p = new ListNode(val);
            if (head == NULL) {
                head = p;
            }
            if (temp) temp->next = p;
            temp = p;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            if (high != 0) {
                ListNode *q = new ListNode(high);
                temp->next = q;
            }
        }
        return head;
    }
};