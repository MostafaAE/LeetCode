const int OO = 1e6;
class Solution {
public:
    /* 
    * Approach:
    * Dijkstra shortest path algorithm
    * 
    * Complexity:
    * Time Complexity : O(E*logV)
    * Space Complexity : O(E+V)
    */
    
    struct edge{
        int to, weight;
        edge(int to, int w) : to(to), weight(w) {}
        
        bool operator <(const edge& e) const
        {
            return weight > e.weight;
        }
        
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<edge>> adjList(n);
        
        for(const vector<int>& t : times)
            adjList[t[0]-1].push_back({t[1]-1, t[2]});
        
        vector<int> dist = Dijkstra(adjList, n, k-1);
        
        int minTime = *max_element(dist.begin(), dist.end());
        
        if(minTime == OO)
            return -1;
        
        return minTime;
    }
    
    vector<int> Dijkstra(vector<vector<edge>>& adjList, int n, int src)
    {
        vector<bool> vis(n, false);
        vector<int> dist(n, OO);
        dist[src] = 0;
        
        priority_queue<edge> pq;
        pq.push(edge(src, 0));
        
        while(!pq.empty())
        {
            edge mnEdge = pq.top();
            int minIdx = mnEdge.to;
            pq.pop();
            
            if(vis[minIdx])
                continue;
            
            for(const edge& edge : adjList[minIdx])
            {
                int to = edge.to, weight = edge.weight;
                
                if(dist[to] > dist[minIdx] + weight)
                {
                    dist[to] = dist[minIdx] + weight;
                    pq.push({to, dist[to]});
                }
            }
                    
            vis[minIdx] = true;
        }
        
        return dist;
    }
};