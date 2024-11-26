class Solution {
public:
    /**
     * Approach:
     * 1. Create an `indegree` array to count incoming edges for each node.
     * 2. Traverse the `edges` and update the `indegree` for the destination node of each edge.
     * 3. Find the node with `indegree` equal to `0`:
     *    - If more than one node has `indegree == 0`, return `-1` (no unique champion).
     *    - Otherwise, return the node index as the champion.
     * 
     * Complexity:
     * Time Complexity: O(n + m)
     * - (O(m)) to process all edges (where (m) is the number of edges).
     * - (O(n)) to check the `indegree` array (where (n) is the number of nodes).
     * Space Complexity: O(n)
     * - Space for the `indegree` array.
     */
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        int result{-1};
        vector<int> indegree(n, 0);
        
        for (auto edge : edges)
            indegree[edge[1]]++;
        
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(indegree[i] == 0)
            {
                // No unique champion
                if(result != -1)
                    return -1;
                
                result = i;
            }
        }
        
        return result;
    } 
};