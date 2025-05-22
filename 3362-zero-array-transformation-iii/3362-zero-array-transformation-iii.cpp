class Solution {
public:
    /*
     * Approach:
     * Greedy + Priority Queue (Max-Heap)
     * 
     * For each index `i`, we want to ensure at least `nums[i]` active removals are ongoing at that index.
     * - We use a max-heap to always prioritize the farthest available end index from current index.
     * - We maintain an `end[]` array to track when each removal ends (delayed prefix sum).
     * - If at some index `i`, we need more active removals than currently available, we pull more from the heap.
     *   If we cannot (heap empty or only offers expired ranges), we return -1.
     * 
     * Time Complexity: 
     * - O(N + Q * log Q + Q * log Q) ≈ O(N + Q log Q)
     *   where N = size of nums, Q = number of queries.
     *   Sorting queries takes O(Q log Q), and heap operations take log Q.
     * 
     * Space Complexity: O(Q + N)
     * - Heap, end[] array, and other temporary variables.
     */
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        int q = queries.size();

        // Sort queries by start index (greedy order)
        sort(queries.begin(), queries.end());

        priority_queue<int> maxHeap; // stores end indices of available queries

        vector<int> end(n + 1, 0); // end[i] = number of removals ending at i - 1
        int activeRemovals = 0;    // number of active removals at current index
        int queryIndex = 0;        // pointer to iterate through sorted queries

        for (int i = 0; i < n; ++i) 
        {
            // Reduce active removals by removals that ended at this index
            activeRemovals -= end[i];

            // Add all new queries that start at or before current index
            while (queryIndex < q && queries[queryIndex][0] <= i) 
            {
                maxHeap.push(queries[queryIndex][1]);
                queryIndex++;
            }

            // Ensure enough active removals to satisfy nums[i]
            while (activeRemovals < nums[i]) 
            {
                // No valid queries left or all have ended before current index
                if (maxHeap.empty() || maxHeap.top() < i) 
                    return -1;

                // Use query with the farthest end index
                int endIdx = maxHeap.top();
                maxHeap.pop();

                // Mark that a removal will end at endIdx + 1
                end[endIdx + 1]++;
                activeRemovals++;
            }
        }

        // Remaining queries in the heap were unused
        return maxHeap.size();
    }
};