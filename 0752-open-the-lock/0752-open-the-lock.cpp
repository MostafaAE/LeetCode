class Solution {
public:
    /**
     * Approach:
     * - We treat the lock as a **graph traversal problem**, where each state (combination of four digits) is a node.
     * - Each wheel can be rotated forward or backward, generating **8 possible moves per state**.
     * - We use **Breadth-First Search (BFS)** to find the shortest path from `"0000"` to `target`.
     * - We use a **hash set (`visited`)** to track visited states and avoid deadends.
     * 
     * Complexity Analysis:
     * - **Total number of states** = O(10⁴) (since each digit has 10 values, and there are 4 digits).
     * - **Time Complexity**: O(8 × 10⁴) = O(1) (since BFS explores at most 10,000 states).
     * - **Space Complexity**: O(10⁴) = O(1) (storing visited states and queue).
     */
    int openLock(vector<string>& deadends, string target) 
    {
        const int D = 4; // Number of digits
        string start = "0000";
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> q;

        if (visited.count(start)) 
            return -1; // Cannot start if it's a deadend
        if (target == start) 
            return 0; // Already unlocked
        
        q.push(start);
        visited.insert(start);
        int level = 0;
        
        while (!q.empty()) 
        {
            int sz = q.size();
            
            while (sz--) {
                string cur = q.front();
                q.pop();

                for (int i = 0; i < D; i++) 
                {
                    char original = cur[i]; // Save original state

                    // Move wheel forward
                    cur[i] = next(original);
                    if (process(q, visited, cur, target)) 
                        return level + 1;
                    
                    // Move wheel backward
                    cur[i] = prev(original);
                    if (process(q, visited, cur, target)) 
                        return level + 1;

                    // Restore original state
                    cur[i] = original;
                }
            }
            ++level; // Increment BFS depth level
        }
        return -1; // Target cannot be reached
    }

private:
    /**
     * Helper function to process the next lock state:
     * - If `str` matches `target`, return `true`.
     * - If `str` is not visited, mark it visited and push it into the queue.
     */
    bool process(queue<string>& q, unordered_set<string>& visited, string str, string target) 
    {
        if (str == target) return true;
        if (visited.insert(str).second) // If not visited, add to queue
            q.push(str);
        return false;
    }

    // Increment digit with wrap-around
    char next(char c) 
    {
        return (c == '9') ? '0' : c + 1;
    }

    // Decrement digit with wrap-around
    char prev(char c) 
    {
        return (c == '0') ? '9' : c - 1;
    }
};