/**
 * Approach:
 * - Step 1: Build the graph as an undirected weighted graph.
 * - Step 2: Run Dijkstra's algorithm from node n-1 to compute shortest distances to all nodes.
 * - Step 3: Use DFS with memoization (`cntPaths`) to count paths from node 0 to node n-1,
 *           ensuring that for each edge (u → v), dist[u] > dist[v] (i.e., distance is decreasing).
 * 
 * Time Complexity:
 * - Dijkstra: O((V + E) * log V)
 * - cntPaths (DFS with memoization): O(V + E)
 * 
 * Space Complexity:
 * - O(V + E) for the graph, O(V) for distance and memo arrays.
 */

class Solution {
private:
    const long long MOD = 1e9 + 7;
    const long long OO = 2e9 + 10;
    const static int MAX_N = 2 * 1e4 + 1;
    long long memory[MAX_N]; // Memoization for cntPaths

    struct edge {
        int to;
        long long w;

        edge(int to, long long w) : to(to), w(w) {}

        bool operator <(const edge &e) const {
            return w > e.w; // For min-heap in Dijkstra
        }
    };

    // Standard Dijkstra's algorithm from target to all nodes
    vector<long long> Dijkstra(const vector<vector<edge>> &adjList, int n, int src) {
        vector<long long> dist(n, OO);
        vector<bool> vis(n, false);
        dist[src] = 0;

        priority_queue<edge> q;
        q.emplace(src, 0);

        while (!q.empty()) {
            edge mnEdge = q.top();
            q.pop();
            int u = mnEdge.to;

            if (vis[u])
                continue;

            for (const edge &e : adjList[u]) {
                int v = e.to, w = e.w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.emplace(v, dist[v]);
                }
            }

            vis[u] = true;
        }

        return dist;
    }

    // Count restricted paths from `src` to `target` with decreasing distances
    long long cntPaths(int src, int target, vector<vector<edge>> &adjList, vector<long long> &dist) {
        if (src == target)
            return 1;

        auto &ret = memory[src];
        if (ret != -1)
            return ret;

        ret = 0;
        for (const edge &e : adjList[src]) {
            if (dist[src] > dist[e.to]) {
                ret += cntPaths(e.to, target, adjList, dist);
                ret %= MOD;
            }
        }

        return ret;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges) {
        vector<vector<edge>> adjList(n);

        // Build undirected graph
        for (const auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1, w = e[2];
            adjList[u].emplace_back(v, w);
            adjList[v].emplace_back(u, w);
        }

        // Get shortest distance from node n-1 to all others
        vector<long long> dist = Dijkstra(adjList, n, n - 1);

        memset(memory, -1, sizeof(memory));

        // Start DFS from node 0 to n-1
        return cntPaths(0, n - 1, adjList, dist);
    }
};
