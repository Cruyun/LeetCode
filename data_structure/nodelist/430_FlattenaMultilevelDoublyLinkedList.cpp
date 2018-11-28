/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }
    Node* helper(Node *head) {
        if (!head) {
            return NULL;
        }
        Node *next = head->next;
        Node *child = head->child;
        head->child = NULL;
        Node *childTail = helper(child);
        Node *nextTail = helper(next);
        
        if (childTail) {
            childTail->next = next;
            child->prev = head;
            head->next = child;
            if (next) {
                next->prev = childTail;
            }
        }
        
        if (nextTail) return nextTail;
        if (childTail) return childTail;
        return head;
    }
};