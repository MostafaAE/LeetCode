typedef unordered_map<int, unordered_set<int>> HASHSET;

class Solution {
public:
    /**
     * Approach:
     * - This problem is modeled as a state-space search using **BFS**.
     * - Each state represents the amount of water in both jugs (j1, j2).
     * - We explore six possible operations at each step:
     *   1. Empty jug 1.
     *   2. Empty jug 2.
     *   3. Fill jug 1 to its capacity.
     *   4. Fill jug 2 to its capacity.
     *   5. Pour water from jug 1 into jug 2.
     *   6. Pour water from jug 2 into jug 1.
     * - A **hash set** tracks visited states to avoid redundant processing.
     * - If any state reaches `targetCapacity`, return `true`.
     * - If the sum of both jugs is less than `targetCapacity`, return `false` immediately.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(cap1 * cap2), as each unique state (j1, j2) is processed once.
     * - **Space Complexity**: O(cap1 * cap2), for the visited states stored in the hash set.
     */
    bool canMeasureWater(int cap1, int cap2, int targetCapacity) 
    {
        if(cap1 + cap2 == targetCapacity || cap1 == targetCapacity || cap2 == targetCapacity)
            return true;
        
        if (cap1 + cap2 < targetCapacity)
            return false;
        
        queue<pair<int, int>> q;
        HASHSET visited;
        q.push({0, 0});
        visited[0].insert(0);
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                auto [j1, j2] = q.front();
                q.pop();
                
                int m1 = min(j1, cap2 - j2); // Amount of water transferred from jug1 to jug2
                int m2 = min(j2, cap1 - j1); // Amount of water transferred from jug2 to jug1
                
                if(process(q, visited, 0, j2, targetCapacity) ||  // Empty jug1
                   process(q, visited, j1, 0, targetCapacity) ||  // Empty jug2
                   process(q, visited, cap1, j2, targetCapacity) ||  // Fill jug1
                   process(q, visited, j1, cap2, targetCapacity) ||  // Fill jug2
                   process(q, visited, j1 - m1, j2 + m1, targetCapacity) ||  // Pour jug1 → jug2
                   process(q, visited, j1 + m2, j2 - m2, targetCapacity))    // Pour jug2 → jug1
                    return true;
            }
        }
        
        return false;
    }
    
private:
    /**
     * Process a new state (j1, j2) and add it to the queue if it's not visited.
     * 
     * Time Complexity: O(1) per operation.
     * Space Complexity: O(1) per insertion in the hash set.
     */
    bool process(queue<pair<int,int>> &q, HASHSET& visited, int j1, int j2, int targetCapacity)
    {
        if(j1 + j2 == targetCapacity || j1 == targetCapacity || j2 == targetCapacity)
            return true;
        
        // Optimization: Store states in (small, large) order to reduce redundant searches
        if(j1 > j2)
            swap(j1, j2);
        
        if(visited[j1].insert(j2).second) // Insert if not already visited
            q.push({j1, j2});
        
        return false;
    }
};