struct Edge
{
    int to;
    // to store the direction we use true indicating a road from a to b for a
    bool built;
};

typedef vector<vector<Edge>> GRAPH;

class Solution {
private:
    int minChanges{};
    
public:
    /* 
    * Approach:
    * build an undirected graph using the connections and perform dfs on node "0" to count the
    * minimum changes we need to make all paths lead to "City Zero"
    * 
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<bool> visited(n,0);
        GRAPH graph(n);
        
        for(auto &p : connections)
            addUndirectedEdge(graph, p[0], p[1]);

        // start dfs from city  0 
        // whenever you find a built edge then it need to be reversed to make the path lead to "0"
        dfs(graph, 0, visited);
        
        return minChanges;
    }
    
    void dfs(GRAPH& graph, int node, vector<bool>& visited)
    {
        visited[node] = 1;
        for(Edge e : graph[node])
        { 
            if(!visited[e.to])
            {
                // reorder the path 
                minChanges += e.built;
                dfs(graph, e.to, visited);
            }
        }
    }
    
    void addUndirectedEdge(GRAPH& graph, int from, int to)
    {
        graph[from].push_back({to, true});
        graph[to].push_back({from, false});
    }
};