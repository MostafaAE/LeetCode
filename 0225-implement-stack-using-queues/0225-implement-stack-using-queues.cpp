class MyStack {
private:

    queue<int> q1, q2;
    int topVal;
public:
    MyStack() {
        
    }
    
    // O(1)
    void push(int x) 
    {
        q1.push(x);
        topVal = x;
    }
    
    // O(n)
    int pop() 
    {
        int val = topVal;
        while(q1.size() > 1)
        {
            topVal = q1.front();
            q1.pop();
            q2.push(topVal);
        }
        q1.pop();
        swap(q1, q2);
       
        return val;
    }
    
    // O(1)
    int top() 
    {
        return topVal;
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