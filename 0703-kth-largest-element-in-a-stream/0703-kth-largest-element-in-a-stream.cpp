class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int _k, vector<int>& nums) 
    {
        k = _k;
        for(int val : nums)
            tryInsert(val);
    }
    
    int add(int val) 
    {
        tryInsert(val);
        return minHeap.top();
    }
    
private:
    void tryInsert(int val)
    {
        if(minHeap.size() == k && val > minHeap.top())
                minHeap.pop();

        if(minHeap.size() < k)
            minHeap.push(val);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */