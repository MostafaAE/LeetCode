/**
 * Approach:
 * - We use Prim’s algorithm to construct the Minimum Spanning Tree (MST).
 * - The graph is implicit: edges are calculated on the fly based on Manhattan distance.
 * - At each step, we pick the minimum-cost edge that connects a new point to the MST.
 * 
 * Time Complexity:
 * - O(E * log v), where v is the number of points.
 *   - For each node added, we may process up to n edges.
 * 
 * Space Complexity:
 * - O(v) for visited, dist, and priority queue.
 */

class Solution {
private:
    const int OO = INT_MAX;

    struct edge {
        int to, weight;

        edge(int to, int weight) : to(to), weight(weight) {}

        // Min-heap based on weight
        bool operator <(const edge& e) const {
            return weight > e.weight;
        }
    };

    // Generate edges from `idx` to all other points with Manhattan distance
    vector<edge> getEdges(vector<vector<int>>& points, int idx) {
        int n = points.size();
        vector<edge> edges;
        
        for (int j = 0; j < n; j++) {
            if (j == idx) continue;
            int distance = abs(points[idx][0] - points[j][0]) +
                           abs(points[idx][1] - points[j][1]);
            edges.emplace_back(j, distance);
        }

        return edges;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> dist(n, OO);             // Minimum cost to connect to the MST
        priority_queue<edge> pq;

        dist[0] = 0;
        pq.push({0, 0});

        int totalCost = 0;

        while (!pq.empty()) {
            edge minEdge = pq.top();
            pq.pop();

            int u = minEdge.to;
            int w = minEdge.weight;

            if (visited[u]) continue;

            totalCost += w;

            // Mark node as added to the MST
            visited[u] = true;

            // Explore edges to all unvisited nodes
            for (edge& e : getEdges(points, u)) {
                int v = e.to;
                int weight = e.weight;

                if (!visited[v] && dist[v] > weight) {
                    dist[v] = weight;
                    pq.push({v, weight});
                }
            }
        }

        return totalCost;
    }
};