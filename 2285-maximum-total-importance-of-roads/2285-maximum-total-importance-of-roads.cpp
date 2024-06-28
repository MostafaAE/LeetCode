class Solution {
public:
    /**
     * Approach:
     * - The importance of a node is proportional to its indegree (number of connections).
     * - To maximize the total importance, assign the highest importance to the node with the highest indegree.
     * - First, calculate the indegree of each node.
     * - Sort the indegree values in ascending order.
     * - Assign importances from 1 to n to the nodes in the order of their sorted indegree values.
     * - Calculate the total importance by summing the products of the assigned importance and the corresponding indegree value.
     *
     * Complexity:
     * - Time Complexity: O(E + nlogn), where E is the number of edges (roads).
     *     - Calculating indegrees takes O(E) time.
     *     - Sorting the indegree array takes O(nlogn) time.
     *     - Calculating the total importance takes O(n) time.
     * - Space Complexity: O(n), for storing the indegree array.
     */
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        long long result{};
        vector<int> indegree(n, 0);
        
        // Calculate the indegree of each node
        for(auto& road : roads)
            ++indegree[road[0]], ++indegree[road[1]];
        
        // Sort the indegree values
        sort(indegree.begin(), indegree.end());
        
        // Assign importance values from 1 to n
        for(int i = 1; i <= n; ++i)
            result += (i * (long long)indegree[i - 1]);
            
        return result;
    }
};
