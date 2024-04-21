class MedianFinder {
private:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
public:
    /*
     * Approach:
     * Maintain two heaps to store the smaller half (left) and larger half (right) of the numbers respectively.
     * When adding a number, ensure it is placed in the correct heap based on its value.
     * Then, balance the heaps if necessary to ensure the size difference between them is at most 1.
     * For finding the median, if the size of the left heap is greater than the size of the right heap,
     * return the top element of the left heap, which represents the median. Otherwise, calculate the
     * median as the average of the tops of both heaps.
     *
     * Complexity:
     * Adding a number: O(log n)
     * Finding the median: O(1)
     * where n is the total number of elements added.
     */
    MedianFinder() {}
    
    //O(logn)
    void addNum(int num) {
        if(leftMaxHeap.empty() || num <= leftMaxHeap.top())
            leftMaxHeap.push(num);
        else
            rightMinHeap.push(num);
        
        if(leftMaxHeap.size() > rightMinHeap.size() + 1)
            rightMinHeap.push(leftMaxHeap.top()), leftMaxHeap.pop();
        else if(rightMinHeap.size() > leftMaxHeap.size())
            leftMaxHeap.push(rightMinHeap.top()), rightMinHeap.pop();
    }
    
    // O(1)
    double findMedian() {
        if(leftMaxHeap.size() > rightMinHeap.size())
            return leftMaxHeap.top();
        
        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */