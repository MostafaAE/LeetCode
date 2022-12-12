class MyCircularQueue {
private:
    int *arr;
    int front{0}, rear{-1};
    int addedElements{};
    int size;
    
    int next(int idx)
    {
        idx++;
        if(idx == size)
            idx = 0;
        return idx;
    }
    
public:
    MyCircularQueue(int k) : size(k)
    {
        arr = new int[k];
    }
    
    // O(1)
    bool enQueue(int value) 
    {
        if(isFull())
            return false;
        
        rear = next(rear);
        arr[rear] = value;
        addedElements++;
        return true;
    }
    
    // O(1)
    bool deQueue() 
    {
        if(isEmpty())
            return false;
        
        front = next(front);
        addedElements--;
        return true;
    }
    
    // O(1)
    int Front() 
    {
        if(isEmpty())
            return -1;
        
        return arr[front];
    }
    
    // O(1)
    int Rear() 
    {
        if(isEmpty())
            return -1;
        
        return arr[rear];
    }
    
    // O(1)
    bool isEmpty() 
    {
        return addedElements == 0;
    }
    
    // O(1)
    bool isFull() 
    {
        return addedElements == size;
    }
    
    ~MyCircularQueue()
    {
        delete[] arr;
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