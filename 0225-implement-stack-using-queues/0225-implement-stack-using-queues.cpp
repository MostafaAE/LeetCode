class MyStack {
private:
    // Follow-up: Can you implement the stack using only one queue?
    queue<int> q;
    
public:
    MyStack() {
        
    }
    
    // O(n)
    void push(int x) 
    {
        q.push(x);
        for(int i = 0 ; i < (int)q.size() - 1 ; i++)
            q.push(q.front()), q.pop();
    }
    
    // O(1)
    int pop() 
    {
        int val = q.front();
        q.pop();
        return val;
    }
    
    // O(1)
    int top() 
    {
        return q.front();
    }
    
    // O(1)
    bool empty() 
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */