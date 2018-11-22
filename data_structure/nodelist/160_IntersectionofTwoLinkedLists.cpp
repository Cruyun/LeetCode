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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        int lenA = 0;
        int lenB = 0;
        
        while (nodeA) {
            nodeA = nodeA->next;
            lenA++;
        }
        while (nodeB) {
            nodeB = nodeB->next;
            lenB++;
        }
        nodeA = headA;
        nodeB = headB;
        while (lenA > lenB) {
            nodeA = nodeA->next;
            lenA--;
        }
        while(lenB > lenA) {
            nodeB = nodeB->next;
            lenB--;
        }
        while (nodeA != NULL) {
            if (nodeA == nodeB) {
                return nodeA;
            }
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return NULL;
    }
};