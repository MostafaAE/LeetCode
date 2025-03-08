class Solution {
public:
    /**
     * Approach:
     * - We use **Breadth-First Search (BFS)** to explore all possible positions in the array.
     * - Each index `i` allows movement to `i + arr[i]` or `i - arr[i]`.
     * - We start from `start` and use a queue to explore all reachable indices.
     * - If we reach an index where `arr[i] == 0`, we return `true`.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n), where `n` is the array size.
     *   - Each index is processed at most once.
     * - **Space Complexity**: O(n) for the `visited` array and queue in the worst case.
     */
    bool canReach(vector<int>& arr, int start) 
    {
        if (arr[start] == 0) return true; // If already at zero, return true

        int n = arr.size();
        vector<bool> visited(n, false); // Track visited indices
        queue<int> q;

        q.push(start);
        visited[start] = true;

        int ops[] = {-1, 1}; // Possible moves (left and right)
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for (int op : ops)
            {
                int neighbour = cur + arr[cur] * op;
                
                // Check bounds and if not visited
                if (neighbour >= 0 && neighbour < n && !visited[neighbour])
                {
                    if (arr[neighbour] == 0) return true; // Found a zero
                    
                    q.push(neighbour);
                    visited[neighbour] = true; // Mark as visited
                }
            }
        }
        
        return false; // No valid path to zero
    }
};
