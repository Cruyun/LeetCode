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
    ListNode *temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return Helper(temp);
    }
    bool Helper(ListNode* node) {
        if (!node) {
            return true;
        }
        bool res = Helper(node->next) && (temp->val == node->val);
        temp = temp->next;
        return res;
    }
};