const int OO = 1e9;
const int RED = 0;
const int BLUE = 1;
struct Edge
{
    int to;
    int color; // 0 for red, 1 for blue
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
        vector<int> answer(n, -1);
        GRAPH graph(n);
        
        // building the graph
        for(auto &p : redEdges)
            addDirectedEdge(graph, p[0], p[1], RED);
        for(auto &p : blueEdges)
            addDirectedEdge(graph, p[0], p[1], BLUE);
        
        bfs(graph, answer);
        
        return answer;
    }
    
    void bfs(GRAPH& graph, vector<int>& answer)
    {
        queue<Edge> q;
        vector<vector<int>> len((int)graph.size(), vector<int>(2, OO));
        
        q.push({0, RED});
        q.push({0, BLUE});
        answer[0] = 0;
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
                    if(e.color != color && len[e.to][e.color] == OO)
                    {
                        q.push(e);

                        len[e.to][e.color] = level + 1;
                        
                        if(answer[e.to] == -1)
                            answer[e.to] = level + 1;
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