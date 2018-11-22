struct MyLinkedListNode {
    int val;
    MyLinkedListNode *prev;
    MyLinkedListNode *next;
    
    MyLinkedListNode(int v) : val(v), prev(NULL), next(NULL) {}
    MyLinkedListNode(int v, MyLinkedListNode *p, MyLinkedListNode *n) : val(v), prev(p), next(n) {}
};

class MyLinkedList {
private:
    MyLinkedListNode *head, *tail;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = new MyLinkedListNode(0);
        tail = new MyLinkedListNode(0);
        head->next = tail;
        tail->prev = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    MyLinkedListNode *findFromHead(int index) {
        int i = 0;
        MyLinkedListNode *cur = head->next;
        while(cur != tail) {
            if (i == index) {
                return cur;
            }
            i++;
            cur = cur->next;
        }
        return NULL;
    }
    MyLinkedListNode *findFromTail(int index) {
        int i = size - 1;
        MyLinkedListNode *cur = tail->prev;
        while (cur != head) {
            if (i == index) {
                return cur;
            }
            i--;
            cur = cur->prev;
        }
        return NULL;
    }
    MyLinkedListNode *find(int index) {
        if(index > size / 2)
            return findFromTail(index);
        
        return findFromHead(index);
    }
    int get(int index) {
        if (index >= size || index < 0) {
            return -1;
        }
        MyLinkedListNode *node = find(index);

        if (node != NULL) {
            return node->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedListNode *node = new MyLinkedListNode(val, head, head->next);
        head->next = head->next->prev = node;
        size += 1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedListNode *node = new MyLinkedListNode(val, tail->prev, tail);
        tail->prev = tail->prev->next = node;
        size += 1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) {
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        MyLinkedListNode *cur = find(index);
        if (cur) {
            cur = cur->prev;
            MyLinkedListNode *node = new MyLinkedListNode(val, cur, cur->next);
            cur->next = cur->next->prev = node;
            size += 1;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        MyLinkedListNode *cur = find(index);
        if (cur) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            size -= 1;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */