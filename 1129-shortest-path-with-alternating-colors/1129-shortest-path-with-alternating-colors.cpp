struct Edge
{
    int to;
    int color; // 1 for red, 2 for blue
};

typedef vector<vector<Edge>> GRAPH;

class Solution {
public:
    /* 
    * Approach:
    * Breadth first serach
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<int> result(n, -1);
        GRAPH graph(n);
        
        for(auto &p : redEdges)
            addDirectedEdge(graph, p[0], p[1], 1);
        
        for(auto &p : blueEdges)
            addDirectedEdge(graph, p[0], p[1], 2);
        
        bfs(graph, result);
        
        return result;
    }
    
    void bfs(GRAPH& graph, vector<int>& length)
    {
        queue<Edge> q;
        vector<pair<bool,bool>> visited((int)graph.size());
        
        q.push({0, 0});
        length[0] = 0;
        int level{};
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                auto [node, color] = q.front();
                q.pop();
                
                for(Edge e : graph[node])
                {
                    if(e.color == 1 && visited[e.to].first || e.color == 2 && visited[e.to].second)
                        continue;
                    
                    if(e.color != color)
                    {
                        q.push(e);
                        
                        if(length[e.to] == -1)
                            length[e.to] = level + 1;
                        
                        if(e.color == 1)
                            visited[e.to].first = 1;
                        else
                            visited[e.to].second = 1;
                    }
                }
            }
            level++;
        }
    }
    
    void addDirectedEdge(GRAPH& graph ,int from, int to, int color)
    {
        graph[from].push_back({to,color});
    }
};