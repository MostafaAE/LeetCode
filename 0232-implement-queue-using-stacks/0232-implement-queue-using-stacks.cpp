class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    // O(1)
    void push(int x) 
    {
        s1.push(x);
    }
    
    // Amortized O(1)
    int pop() 
    {
        if(s2.empty())
            while(!s1.empty())
                s2.push(s1.top()) , s1.pop();
        
        int ret = s2.top();
        s2.pop();
        return ret;
    }
    
    // Amortized O(1)
    int peek() 
    {
        if(s2.empty())
            while(!s1.empty())
                s2.push(s1.top()) , s1.pop();
        
        return s2.top();
    }
    
    // O(1)
    bool empty() 
    {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */