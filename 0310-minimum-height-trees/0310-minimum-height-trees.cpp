typedef vector<vector<int>> GRAPH;
class Solution {
public:
    	
    /* 
    * Approach:
    * Like topological sort but graph is undirected, the focus on in-degree = 1 
    * and we will stop when there are nodes <= 2
    *
    * How many MHTs can a graph have at most? only 1 if n is odd and 2 if n is even
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        GRAPH graph(n);
        vector<int> indegree(n, 0);
        vector<int> result;
        int nodes = n;
        
        if(n == 1)      // special case
            return {0};

        // building the graph
        for(auto &p : edges)
        {
            addUndirectedEdge(graph, p[0], p[1]);
            indegree[p[0]]++;
            indegree[p[1]]++;
        }
        
        queue<int> ready;
        for(int i = 0 ; i < n ; i++)
            if(indegree[i] == 1)    // leaves
                ready.push(i);
        
        // keep shrinking leaves: level by level
        while(nodes > 2)
        {
            int sz = ready.size();
            nodes -= sz;    // how many leaves NOW
            
            while(sz--)
            {
                int cur = ready.front();
                ready.pop();
                
                for(int neighbour : graph[cur])
                    if(--indegree[neighbour] == 1)
                        ready.push(neighbour);
            }
        }
        
        while(!ready.empty())
            result.push_back(ready.front()), ready.pop();
        
        return result;
    }
    
    
    void addUndirectedEdge(GRAPH &graph, int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
};