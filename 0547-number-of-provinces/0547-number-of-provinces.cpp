class Solution {
public:
    /*
     * Approach:
     * Graph Depth-First Search
     *
     * Complexity:
     * Time Complexity : O(n^2)
     * Space Complexity : O(n)
     */
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n{(int)isConnected.size()}, provinces{};
        vector<int> visited(n, 0);
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                provinces++;
                dfs(isConnected, i, visited);
            }
        }
        
        return provinces;
    }
    
    void dfs(vector<vector<int>>& graph, int node, vector<int>& visited)
    {
        visited[node] = true;
        
        for(int i = 0 ; i < (int)graph[node].size() ; i++)
            if(graph[node][i] && !visited[i])
                dfs(graph, i, visited);
    }
};