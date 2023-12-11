const int OO = 2 * 1e6 * 1000; // careful from OO value

class Solution {
public:
    
    /* 
    * Approach:
    * Graph Prim's MST (lazy building the adjacency list)
    * 
    * Complexity:
    * Time Complexity : O(ElogV)
    * Space Complexity : O(V)
    */

    struct edge
    {
        int to, w;

        edge(int to, int w) : to(to), w(w){}

        bool operator<(const edge &e) const
        {
            return w > e.w;
        }
    };
    
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n{(int)points.size()}, src{};
        vector<int> dist(n, OO);
        vector<bool> vis(n, 0);
        dist[src] = 0;
        int mstCost = 0;

        priority_queue<edge> q; // small to large
        q.push(edge(src, 0));

        while (!q.empty())
        {
            // Get node with the minimum distance
            edge mnEdge = q.top();
            int mnIdx = mnEdge.to;
            q.pop();

            if (vis[mnIdx]) // visited
                continue;

            mstCost += mnEdge.w;

            for (const auto &edge : getEdges(points, mnIdx))
            { // relax
                int to = edge.to, weight = edge.w;

                if (dist[to] > weight)
                {
                    dist[to] = weight;
                    q.push({to, dist[to]});
                }
            }
            vis[mnIdx] = true;
        }
        
        return mstCost;
    }
    
    vector<edge> getEdges(vector<vector<int>>& points, int idx)
    {
        int n{(int)points.size()};
        vector<edge> adjList;
        for(int j = 0 ; j < n ; j++)
        {
            int distance = abs(points[idx][0] - points[j][0]) + abs(points[idx][1] - points[j][1]);
            adjList.push_back({j, distance});
        }
        
        return adjList;
    }
};