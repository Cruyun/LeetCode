class MyCircularQueue {
private:
    int *data;
    int len;
    int front;
    int rear;
    int count;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = new int[k];
        len = k;
        front = 0;
        rear = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            data[rear] = value;
            rear = (rear + 1) % len;
            count++;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            front = (front + 1) % len;
            count--;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : data[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        int temp;
        temp = rear == 0 ? len - 1 : rear - 1;
        return isEmpty() ? -1 : data[temp];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count == len;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */