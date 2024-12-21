class Solution {
public:
    /**
     * Approach:
     * 1. Represent the graph using an adjacency list.
     * 2. Use DFS to compute the sum of values for each subtree modulo `k`.
     * 3. If a subtree's sum modulo `k` is 0, it can form a separate component.
     * 4. Decrement the total number of components whenever a valid subtree is found.
     * 
     * Complexity:
     * Time Complexity: O(n + m) - Building the adjacency list and performing DFS.
     * Space Complexity: O(n + m) - For the adjacency list and recursion stack.
     */
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        // Create an adjacency list for the graph
        vector<vector<int>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        // Start with `n` components
        int result = n;
        
        // Perform DFS to calculate the result
        dfs(adjList, 0, -1, values, k, result);
        
        return result;
    }
    
    int dfs(vector<vector<int>>& adjList, int node, int parent, vector<int>& values, int k, int& result) 
    {
        // Start with the node's value
        int sum = values[node];
        
        // Traverse all neighbors
        for (int neighbor : adjList[node]) 
            if (neighbor != parent) 
                sum += dfs(adjList, neighbor, node, values, k, result), sum %= k;
        
        // If the sum of the subtree is divisible by `k`, it forms a valid component
        if (sum % k == 0)
            return 0; // Reset sum for this subtree
        
        // Otherwise, decrement the result (component count)
        --result;
        return sum;
    }
};
