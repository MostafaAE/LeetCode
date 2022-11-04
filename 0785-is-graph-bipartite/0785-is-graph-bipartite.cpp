typedef vector<vector<int>> GRAPH;
class Solution {
private:
    bool bipartite{1};
public:
    
    /* 
    * Approach:
    * perform DFS and mark each node as 0: uncolored; 1: color A; -1: color B if a node is the same color
    * as its child then the graph is not bipartite
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool isBipartite(GRAPH& graph) 
    {
        // mark each node as 0: uncolored; 1: color A; -1: color B
        vector<int> visited((int)graph.size(), 0);
        
        for(int i = 0 ; i < (int)graph.size() ; i++)
        {
            if(!visited[i])
                dfs(graph, i, visited);
                
            if(!bipartite)
                return false;
        }
        
        return true;
    }
    
    void dfs(GRAPH &graph, int node, vector<int> &visited, int color = 1)
    {
        if(!bipartite)
            return;
        
        visited[node] = color;

        for(int neighbour : graph[node])
        {
            if(!visited[neighbour])
                dfs(graph, neighbour, visited, -color);
            else if(bipartite)
                bipartite = (visited[neighbour] == -color);
        }
    }
};