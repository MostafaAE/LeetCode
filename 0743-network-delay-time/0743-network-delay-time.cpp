/**
 * Approach:
 * - This is a classic single-source shortest path problem on a weighted directed graph.
 * - We use **Dijkstra's algorithm** to find the shortest time it takes for the signal to reach all nodes.
 * - If there's any node that is unreachable (i.e., distance remains infinite), return -1.
 * 
 * Time Complexity: O((E + V) * log V)
 * - E = number of edges, V = number of nodes
 * - Priority queue gives O(log V) operations and each node/edge is processed once.
 * 
 * Space Complexity: O(V + E)
 * - To store the adjacency list and distance array.
 */

class Solution {
private:
    const int OO = 1e6;  // A large value representing infinity

    // Custom edge struct for priority queue with reversed comparator
    struct edge {
        int to, weight;
        edge(int to, int w) : to(to), weight(w) {}

        // This makes the priority_queue a min-heap based on edge weights
        bool operator <(const edge& e) const {
            return weight > e.weight;
        }
    };

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // Create adjacency list: 0-based indexing
        vector<vector<edge>> adjList(n);
        for (const vector<int>& t : times)
        {
            int u = t[0] - 1;
            int v = t[1] - 1;
            int w = t[2];
            adjList[u].emplace_back(v, w);
        }

        // Run Dijkstra from source node k-1
        vector<int> dist = Dijkstra(adjList, n, k - 1);

        // The time it takes is the max distance among all reachable nodes
        int minTime = *max_element(dist.begin(), dist.end());

        return minTime == OO ? -1 : minTime;
    }

    // Standard Dijkstra's algorithm
    vector<int> Dijkstra(vector<vector<edge>>& adjList, int n, int src)
    {
        vector<int> dist(n, OO);   // Distance array
        vector<bool> vis(n, false); // Visited nodes
        dist[src] = 0;

        priority_queue<edge> pq;
        pq.push({src, 0}); // Start with source node

        while (!pq.empty())
        {
            edge mnEdge = pq.top();
            pq.pop();
            int u = mnEdge.to;

            if (vis[u])
                continue;

            vis[u] = true;

            for (const edge& e : adjList[u])
            {
                int v = e.to;
                int w = e.weight;

                // Relax the edge
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({v, dist[v]});
                }
            }
        }

        return dist;
    }
};