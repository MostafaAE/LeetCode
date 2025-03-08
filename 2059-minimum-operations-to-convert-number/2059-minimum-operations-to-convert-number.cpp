class Solution {
public:
    /**
     * Approach:
     * - We use **Breadth-First Search (BFS)** to find the shortest sequence of operations to reach `goal` from `start`.
     * - At each step, we can:
     *   - Add `nums[i]` to `cur`
     *   - Subtract `nums[i]` from `cur`
     *   - XOR `cur` with `nums[i]`
     * - We maintain a queue for BFS traversal and a `visited` array to prevent redundant computations.
     * - If we reach `goal`, we return the number of operations.
     * - If no path is found, return `-1`.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n * k), where `n` is the size of `nums` and `k` is the number of unique values processed (at most 1001).
     *   - Each value can have three transitions, leading to a worst-case factor of `O(n)`.
     * - **Space Complexity**: O(k) = O(1001) = O(1) (since `visited` array has a fixed size).
     */
    int minimumOperations(vector<int>& nums, int start, int goal) 
    {
        int n = nums.size();
        
        vector<bool> visited(1001, false); // Track visited numbers within range [0, 1000]
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        int level = 0;
        
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int cur = q.front();
                q.pop();
                
                for (int i = 0; i < n; i++)
                {
                    // Try all three operations and check if we reach the goal
                    if (process(q, visited, cur + nums[i], goal) || 
                        process(q, visited, cur - nums[i], goal) || 
                        process(q, visited, cur ^ nums[i], goal))
                        return level + 1;
                }
            }
            
            ++level;
        }
        
        return -1; // Goal cannot be reached
    }
    
    /**
     * Helper function to process the next number:
     * - If `num` is equal to `goal`, return true.
     * - If `num` is within range [0, 1000] and not visited, mark it visited and push to queue.
     */
    bool process(queue<int>& q, vector<bool>& visited, int num, int goal)
    {
        if (num == goal)
            return true;
        if (num >= 0 && num <= 1000 && !visited[num])
        {
            visited[num] = true;
            q.push(num);
        }
        return false;
    }
};