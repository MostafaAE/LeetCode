const int INF = 1e9;
const int RED = 0;
const int BLUE = 1;

struct Edge
{
    int to;
    int color; // 0 for red, 1 for blue
};

typedef vector<vector<Edge>> GRAPH;

class Solution 
{
public:
    /**
     * Approach:
     * - Construct a directed graph where edges have a color (red or blue).
     * - Use **BFS** to find the shortest alternating path (switching between red and blue).
     * - Maintain a `len` array to track the shortest path for each color.
     * - Use a queue to explore paths, ensuring alternate colors are taken at each step.
     * 
     * Complexity Analysis:
     * - **Graph Construction**: O(n + e), where `e` is the total number of edges.
     * - **BFS Traversal**: O(n + e), since each node and edge is processed once.
     * - **Overall Complexity**: O(n + e).
     */
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<int> answer(n, -1);
        GRAPH graph(n);
        
        // Build the graph
        for(auto &p : redEdges)
            addDirectedEdge(graph, p[0], p[1], RED);
        for(auto &p : blueEdges)
            addDirectedEdge(graph, p[0], p[1], BLUE);
        
        bfs(graph, answer);
        
        return answer;
    }
    
private:
    /**
     * BFS to find shortest alternating paths from node 0.
     */
    void bfs(GRAPH& graph, vector<int>& answer)
    {
        queue<Edge> q;
        vector<vector<int>> len(graph.size(), vector<int>(2, INF));
        
        // Start BFS from node 0 with both red and blue colors
        q.push({0, RED});
        q.push({0, BLUE});
        answer[0] = 0;
        int level = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                auto [node, color] = q.front();
                q.pop();
                
                for(Edge e : graph[node])
                {
                    if(e.color != color && len[e.to][e.color] == INF)
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
    
    /**
     * Adds a directed edge to the graph.
     */
    void addDirectedEdge(GRAPH& graph, int from, int to, int color)
    {
        graph[from].push_back({to, color});
    }
};