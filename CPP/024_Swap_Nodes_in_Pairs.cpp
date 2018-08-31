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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* newNode = head && head->next ? head->next : head;
        while (curr && curr->next) {
            ListNode* next = curr->next;
            ListNode* temp = curr->next->next;
            next->next = curr;
            curr->next = temp && temp->next ? temp->next : temp;
            curr = temp;
        }
        return newNode;
    }
};