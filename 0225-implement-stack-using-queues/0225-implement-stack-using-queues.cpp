class MyStack {
private:
    queue<int> q1, q2;
    int topVal;
    
public:
    MyStack() {
        
    }
    
    // O(n)
    void push(int x) 
    {
        while(!q1.empty())
            q2.push(q1.front()), q1.pop();
        
        q1.push(x);
        
        while(!q2.empty())
            q1.push(q2.front()), q2.pop();
    }
    
    // O(1)
    int pop() 
    {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    // O(1)
    int top() 
    {
        return q1.front();
    }
    
    // O(1)
    bool empty() 
    {
        return q1.empty();
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