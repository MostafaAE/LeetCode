typedef unordered_map<int, vector<int>> GRAPH;
class Solution {
public:
    /* 
    * Approach:
    * reduce the problem to a graph and perfrom depth first search on the start or end node 
    * which appear only once
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        GRAPH graph;
        vector<int> result;
        
        // building the graph
        for(auto &p: adjacentPairs)
            addUndirectedEdge(graph, p[0], p[1]);
        
        // finding the first node (appear once in adjacentPairs) to perfrom DFS on
        for(auto &p : graph)
        {
            if(p.second.size() == 1)
            {
                dfs(graph, p.first, result, p.first);
                break;
            }
        }
        return result; 
    }
    
    void dfs(unordered_map<int, vector<int>> &graph, int node, vector<int>& traversal, int par)
    {
        traversal.push_back(node);

        for(int neighbour : graph[node])
            if(neighbour != par)
                dfs(graph, neighbour, traversal, node);
    }
    
    void addUndirectedEdge(unordered_map<int, vector<int>> &graph, int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
};