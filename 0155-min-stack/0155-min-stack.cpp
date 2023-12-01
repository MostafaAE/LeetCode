class MinStack {
private:
    stack<int> minStack;
    stack<int> data;
public:
    MinStack() {
        
    }
    
    // O(1)
    void push(int val) {
        data.push(val);
        
        if(minStack.empty() || minStack.top() >= val)
            minStack.push(val);
    }
    
    // O(1)
    void pop() {
        if(minStack.top() == data.top())
            minStack.pop();
        data.pop();
    }
    
    // O(1)
    int top() {
        return data.top();
    }
    
    // O(1)
    int getMin() {
        return minStack.top();
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