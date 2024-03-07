class Solution {
public:
    /*
     * Approach:
     * Graph Depth-First Search
     *
     * Complexity:
     * Time Complexity : O(V + E)
     * Space Complexity : O(V)
     */
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n{(int)graph.size()};
        unordered_set<int> safe;
        vector<bool> visited(n, 0);
        
        for(int i = 0 ; i < n ; i++)
            if(!visited[i])
                dfs(graph, i, visited, safe);
        
        vector<int> result(safe.begin(), safe.end());
        sort(result.begin(), result.end());
        return result;
    }
    
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, unordered_set<int>& safe)
    {
        visited[node] = true;
        
        bool isSafe = true;
        
        for(int neighbour : graph[node])
        {
            if(!visited[neighbour])
                dfs(graph, neighbour, visited, safe);

            isSafe &= safe.count(neighbour);
        }
            
        if(isSafe)
            safe.insert(node);
    }
};