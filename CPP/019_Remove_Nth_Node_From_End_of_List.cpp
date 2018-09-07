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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head == NULL) {
        return NULL;
      }

      ListNode* node = head;
      ListNode* prev = NULL;
      int len = 0;

      while (node) {
        node = node->next;
        len++;
      }
      n = len - n;

      node = head;
      if (n == 0) {
        head = head->next;
        delete node;
        return head;
      }
      
      while (n) {
        prev = node;
        node = node->next;
        n--;
      }

      prev->next = node->next;
      delete node;
      return head;
    }
};