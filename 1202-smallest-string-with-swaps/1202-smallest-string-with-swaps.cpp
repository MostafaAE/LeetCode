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
        int nodes = s.size();
        GRAPH graph(nodes);
        vector<bool> visited(nodes, 0);
        
        // building the graph
        for(auto &p: pairs)
            addUndirectedEdge(graph, p[0], p[1]);
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(!visited[i])
            {
                vector<int> ccNodes;
                string ccChars;
                dfs(graph, i, visited, ccNodes);
                
                for(int idx : ccNodes)
                    ccChars += s[idx];
                
                sort(ccChars.begin(), ccChars.end());
                sort(ccNodes.begin(), ccNodes.end());
                
                for(int j = 0 ; j < (int)ccNodes.size() ; j++)
                    s[ccNodes[j]] = ccChars[j];
            }   
        }
        
        return s;
    }
    
    void dfs(GRAPH &graph, int node, vector<bool>& visited, vector<int> &cc)
    {
        cc.push_back(node);
        visited[node] = 1;
        
        for(int neighbour : graph[node])
            if(!visited[neighbour])
                dfs(graph, neighbour, visited, cc);
    }
    
    void addUndirectedEdge(GRAPH &graph, int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
};