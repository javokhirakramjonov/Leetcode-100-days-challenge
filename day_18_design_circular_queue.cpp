class MyCircularQueue {
public:
    int current_size = 0;
    int size;
    int my_queue[3000];
    int l, r;
    
    
    MyCircularQueue(int k) {
        l = r = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        my_queue[++r] = value;
        l = max(l, 0);
        ++current_size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        --current_size;
        ++l;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : my_queue[l];
    }
    
    int Rear() {
        return isEmpty() ? -1 : my_queue[r];
    }
    
    bool isEmpty() {
        return current_size == 0;
    }
    
    bool isFull() {
        return current_size == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
