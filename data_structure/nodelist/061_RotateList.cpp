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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }
        ListNode* t = head;
        int cnt = 0;
        while (t) {
            cnt++;
            t = t->next;
        }
        k = k % cnt;
        
        if (!k) {
            return head;
        }

        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        ListNode* newTail = head;
        for (int i = cnt - 1; i > k; i--) {
            newTail = newTail->next;
        }
        
        ListNode *newhead = newTail->next;
        tail->next = head;
        newTail->next = NULL;
        return newhead; 
    }
};