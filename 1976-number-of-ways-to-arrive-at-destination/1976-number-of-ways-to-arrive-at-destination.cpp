const long long OO = (1e9 + 10) * 200;	// > 200 edge * maxedge-cost;
const long long MOD = 1e9 + 7;
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
        int to;
        long long weight;
        edge(int to, long long w) : to(to), weight(w) {}
        
        bool operator <(const edge& e) const
        {
            return weight > e.weight;
        }
        
    };
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<edge>> adjList(n);
        
        for(auto& e : roads)
        {
            // Undirected edge = 2 directed edges
            adjList[e[0]].push_back({e[1], e[2]});
            adjList[e[1]].push_back({e[0], e[2]});
        }
        
        return Dijkstra(adjList, n, 0, n-1);
    }
    
    long long Dijkstra(vector<vector<edge>>& adjList, int n, int src, int target)
    {
        vector<bool> vis(n, false);
        vector<long long> dist(n, OO);
        vector<long long> cnt(n, 0);
        dist[src] = 0;
        cnt[src] = 1;
        
        
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
                    cnt[to] = cnt[minIdx];
                    pq.push({to, dist[to]});
                }
                
                else if(dist[to] == dist[minIdx] + weight)
                {
                    cnt[to] += cnt[minIdx];
                    cnt[to]  %= MOD;
                }
            }
                    
            vis[minIdx] = true;
        }
        
        return cnt[target];
    }
};