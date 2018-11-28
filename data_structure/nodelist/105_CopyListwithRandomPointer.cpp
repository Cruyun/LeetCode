/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return NULL;
        }
        RandomListNode* node = head;
        while (node) {
            RandomListNode* copy = new RandomListNode(node->label);
            copy->next= node->next;
            node->next = copy;
            node = copy->next;
        }
        
        node = head;
        while (node) {
            if (node->random) {
                node->next->random  = node->random->next;
            }
            node = node->next->next;
        }
        
        RandomListNode *newhead = head->next;
        
        node = head;
        while (node) {
            RandomListNode* temp = node->next;
            node->next = temp->next;
            if (temp->next) {
                temp->next = temp->next->next;
            }
            node = node->next;
        }
        return newhead;
    }
};