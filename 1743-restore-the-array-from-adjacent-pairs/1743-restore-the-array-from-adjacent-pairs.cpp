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
        unordered_map<int, int> count;
        unordered_map<int, unordered_set<int>> graph;
        unordered_set<int> visited;
        vector<int> result;
        
        // building the graph
        for(auto p: adjacentPairs)
        {
            addUndirectedEdge(graph, p[0], p[1]);
            count[p[0]]++;
            count[p[1]]++;
        }
        
        // finding the first node (appear once in adjacentPairs) to perfrom DFS on
        int start{};
        for(auto p : count)
            if(p.second == 1)
                start = p.first;
        
        dfs(graph, start, visited, result);
        
        return result; 
    }
    
    void dfs(unordered_map<int, unordered_set<int>> &graph, int node, unordered_set<int>& visited, vector<int>& traversal)
    {
        visited.insert(node);
        traversal.push_back(node);

        for(int e : graph[node])
            if(!visited.count(e))
                dfs(graph, e, visited, traversal);
    }
    
    void addUndirectedEdge(unordered_map<int, unordered_set<int>> &graph, int from, int to)
    {
        graph[from].insert(to);
        graph[to].insert(from);
    }
};