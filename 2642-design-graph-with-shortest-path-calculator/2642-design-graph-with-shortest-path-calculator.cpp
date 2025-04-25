/**
 * Approach:
 * - We build a directed weighted graph using an adjacency list.
 * - To find the shortest path from source to destination, we use Dijkstra's algorithm.
 * - The graph is dynamic, meaning edges can be added after initialization.
 * 
 * Time Complexity:
 * - Constructor: O(E) for adding edges.
 * - addEdge: O(1)
 * - shortestPath: O((V + E) * log V) using a priority queue (min-heap via custom comparator)
 * 
 * Space Complexity: O(V + E)
 * - Adjacency list + distance array
 */

class Graph {
private:
    struct edge {
        int to, w;

        edge(int to, int w) : to(to), w(w) {}

        // Custom comparator to make the priority_queue a min-heap
        bool operator <(const edge& e) const {
            return w > e.w;
        }
    };

    int n; // Number of nodes
    vector<vector<edge>> adjList; // Adjacency list
    const int OO = INT_MAX; // Infinity constant for unreachable paths

public:
    // Constructor to initialize graph with nodes and edges
    Graph(int nodesCount, vector<vector<int>>& edges) {
        n = nodesCount;
        adjList = vector<vector<edge>>(n);

        for (auto& e : edges) {
            addEdge(e);
        }
    }

    // Adds a directed edge to the graph
    void addEdge(vector<int> edge) {
        int from = edge[0], to = edge[1], weight = edge[2];
        adjList[from].emplace_back(to, weight);
    }

    // Finds the shortest path from src to dest using Dijkstra's algorithm
    int shortestPath(int src, int dest) {
        priority_queue<edge> pq;  // Min-heap for shortest edge selection
        vector<int> dist(n, OO);  // Distance array initialized to infinity

        dist[src] = 0;
        pq.push({src, 0});

        while (!pq.empty()) {
            edge minEdge = pq.top();
            pq.pop();
            int u = minEdge.to, currDist = minEdge.w;

            // If already found a better path before, skip
            if (currDist > dist[u])
                continue;

            // Relax edges from current node
            for (edge& e : adjList[u]) {
                int v = e.to, weight = e.w;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({v, dist[v]});
                }
            }
        }

        return dist[dest] == OO ? -1 : dist[dest];
    }
};

/**
 * Example usage:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1, node2);
 */
