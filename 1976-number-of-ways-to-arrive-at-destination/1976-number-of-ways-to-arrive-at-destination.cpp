/**
 * Approach:
 * - We build an undirected weighted graph from the given `roads`.
 * - We use a modified version of Dijkstra's algorithm to not only compute the shortest distances
 *   but also count the number of shortest paths to each node.
 * - For every node `v`, we track:
 *    - `dist[v]`: the shortest distance from the source to `v`
 *    - `cnt[v]`: the number of shortest paths from the source to `v`
 * - If we find a better (shorter) path, we update both `dist` and `cnt`.
 * - If we find another path with the same shortest distance, we add the path count to `cnt[v]`.
 * 
 * Time Complexity:
 * - Building adjacency list: O(E)
 * - Dijkstra’s traversal: O((V + E) * log V)
 * 
 * Space Complexity: O(V + E) for adjacency list, dist, and cnt arrays.
 */

class Solution {
private:
    const long long OO = (1e9 + 10) * 200; // Larger than any possible path cost
    const long long MOD = 1e9 + 7;

    struct edge {
        int to;
        long long weight;

        edge(int to, long long w) : to(to), weight(w) {}

        // Custom comparator for min-heap behavior in priority_queue
        bool operator <(const edge& e) const {
            return weight > e.weight;
        }
    };

    long long Dijkstra(vector<vector<edge>>& adjList, int n, int src, int target) {
        vector<long long> dist(n, OO); // Shortest distance from source
        vector<long long> cnt(n, 0);   // Count of shortest paths
        dist[src] = 0;
        cnt[src] = 1;

        priority_queue<edge> pq;
        pq.emplace(src, 0);

        while (!pq.empty()) {
            edge curr = pq.top();
            pq.pop();
            int u = curr.to;
            long long currDist = curr.weight;

            // If this is not the shortest path, skip
            if (currDist > dist[u]) continue;

            for (const edge& e : adjList[u]) {
                int v = e.to;
                long long weight = e.weight;

                if (dist[v] > dist[u] + weight) {
                    // Found a shorter path to v
                    dist[v] = dist[u] + weight;
                    cnt[v] = cnt[u]; // Inherit path count
                    pq.emplace(v, dist[v]);
                } else if (dist[v] == dist[u] + weight) {
                    // Found another shortest path to v
                    cnt[v] = (cnt[v] + cnt[u]) % MOD;
                }
            }
        }

        return cnt[target];
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<edge>> adjList(n);

        // Build the undirected graph
        for (auto& e : roads) {
            int u = e[0], v = e[1], w = e[2];
            adjList[u].emplace_back(v, w);
            adjList[v].emplace_back(u, w);
        }

        return Dijkstra(adjList, n, 0, n - 1); // From node 0 to node n-1
    }
};