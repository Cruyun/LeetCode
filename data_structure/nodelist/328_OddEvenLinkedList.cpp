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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode* node = head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* sec = head->next;
        int len = 0;
        while (node) {
            len++;
            if (!node->next) {
                break;
            }
            temp = node->next;
            node->next = node->next->next;
            prev = node;
            node = temp;
        }
        if (len % 2 == 0) {
            prev->next = sec;
        } else {
            node->next = sec;
        }
        return head;
    }
};