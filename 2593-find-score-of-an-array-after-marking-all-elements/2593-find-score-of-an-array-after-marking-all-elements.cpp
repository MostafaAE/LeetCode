class Solution {
public:
    /**
     * Approach:
     * 1. Use a min-heap (priority queue) to process elements in increasing order of their values.
     * 2. Push all elements of `nums` into the min-heap along with their indices. This ensures the smallest element is always processed first.
     * 3. While the heap is not empty:
     *    - Pop the smallest element (value and index).
     *    - If the index is already marked, skip it.
     *    - Otherwise, add the value to the `score` and mark the current index, its left neighbor (if valid), and its right neighbor (if valid) as "marked."
     * 4. Return the accumulated `score`.
     * 
     * Complexity:
     * Time Complexity: O(n log n)
     * - O(n log n) to push all elements into the heap.
     * - O(n log n) to process all elements from the heap, as each push and pop operation takes O(log n).
     * Space Complexity: O(n)
     * - O(n) for the `marked` array.
     * - O(n) for the heap.
     */
    long long findScore(vector<int>& nums) 
    {
        int n = nums.size();
        long long score{};
        vector<bool> marked(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    
        // O(n logn)
        for(int i = 0 ; i < n ; ++i)
        {
            minHeap.push({nums[i], i});
        }
        
        // O(n logn)
        while(!minHeap.empty())
        {
            auto [val, idx] = minHeap.top();
            minHeap.pop();
            
            if(marked[idx])
                continue;
            
            score += val;
            
            marked[idx] = true;
            if(idx > 0)
                marked[idx-1] = true;
            if(idx < n-1)
                marked[idx+1] = true;
        }
        
        return score;
    }
};