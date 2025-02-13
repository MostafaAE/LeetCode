using LL = long long;

class Solution {
public:
    /**
     * Approach:
     * 1. Use a min-heap (priority queue) to efficiently access the smallest elements.
     * 2. Initialize the min-heap with all elements from the input array.
     * 3. While the smallest element is less than `k` and there are at least two elements in the heap:
     *    - Extract the two smallest elements.
     *    - Combine them into a new value using the formula: 
     *         `val = min(first, second) * 2 + max(first, second)`.
     *    - Push the new value back into the min-heap.
     *    - Increment the operation count.
     * 4. Return the total count of operations once the smallest element is at least `k`.
     *
     * Complexity:
     * - Time Complexity: O(n log n), where `n` is the size of `nums`.
     *   - Building the heap is O(n).
     *   - Each push and pop operation in the heap is O(log n), and in the worst case, all elements are processed.
     * - Space Complexity: O(n) for storing elements in the heap.
     **/
    int minOperations(vector<int>& nums, int k) 
    {
        // Initialize min-heap with all elements from the input array (heapify)
        priority_queue<LL, vector<LL>, greater<>> minHeap(nums.begin(), nums.end());

        int count{};
        
        // While the smallest element is less than k and we have at least two elements
        while(minHeap.top() < k && minHeap.size() >= 2)
        {
            LL first = minHeap.top();
            minHeap.pop();
            LL second = minHeap.top();
            minHeap.pop();
            
            minHeap.push(first * 2 + second);

            ++count;
        }

        return count;
    }
};
