class Solution {
public:
    /**
     * Approach:
     * - We use a max-heap (priority queue) to always select the largest element at each step.
     * - After selecting the largest element, we increment the score and reduce the element by dividing it by 3, 
     *   pushing the reduced value back into the heap.
     * 
     * Complexity:
     * - Time Complexity: O(klogn + nlogn), where `n` is the number of elements in the array `nums`, and `k` is the number of selections. 
     * - Space Complexity: O(n), for the heap to store `n` elements.
     */
    long long maxKelements(vector<int>& nums, int k) 
    {
        long long score{};
        priority_queue<int> maxHeap;
        
        for(auto val : nums)
            maxHeap.push(val);
        
        while(k--)
        {
            int topVal = maxHeap.top();
            
            score += topVal;
            
            maxHeap.pop();
            maxHeap.push(ceil(topVal / 3.0));
        }
        
        return score;
    }
};