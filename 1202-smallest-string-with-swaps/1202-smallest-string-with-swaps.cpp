typedef vector<vector<int>> GRAPH;

class Solution {
public:
    /* 
    * Approach:
    * reduce the problem to a graph and get each connected component (DFS)
    * for each connected component sort its letters and put them back ordered from smallest
    */
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        int n{(int)s.size()};
        GRAPH graph(n);
        vector<bool> visited(n);
        string result = s;
        
        for(auto& p : pairs)
            addUndirectedEdge(graph, p[0], p[1]);
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                vector<int> cc;
                string ccStr{};
                
                dfs(graph, i, visited, cc);
                
                for(auto& node : cc)
                    ccStr += s[node];
                
                sort(cc.begin(), cc.end());
                sort(ccStr.begin(), ccStr.end());
                
                for(int j = 0 ; j < (int)cc.size() ; j++)
                    result[cc[j]] = ccStr[j];
            }
        }
        
        return result;
    }
    
    void dfs(GRAPH& graph, int node, vector<bool>& visited, vector<int>& cc)
    {
        visited[node] = true;
        cc.push_back(node);
        
        for(auto& neighbour : graph[node])
            if(!visited[neighbour])
                dfs(graph, neighbour, visited, cc);
    }
    
    void addUndirectedEdge(GRAPH& graph, int from ,int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
};