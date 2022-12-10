class MinStack {
private:
    stack<pair<int, int>> minStack;
public:
    MinStack() 
    {
    }
    
    // O(1)
    void push(int val) 
    {
        if(minStack.empty())
            minStack.push({val, val});
        else
            minStack.push({val, min(val, minStack.top().second)});
        
    }
    
    // O(1)
    void pop() 
    {
        minStack.pop();
    }
    
    // O(1)
    int top() 
    {
        return minStack.top().first;
    }
    
    // O(1)
    int getMin() 
    {
        return minStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */