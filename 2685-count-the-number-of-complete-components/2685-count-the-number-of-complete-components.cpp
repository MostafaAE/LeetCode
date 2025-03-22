class Solution {
public:
    /**
     * Approach:
     * - Represent the graph using an **adjacency list**.
     * - Use **DFS** to traverse each connected component.
     * - For each connected component, track:
     *   - **Number of vertices** (`V`).
     *   - **Total edge count** (`E`).
     * - A complete graph with `V` nodes should have exactly `V * (V - 1) / 2` edges.
     * - Since each edge is counted twice (once for each node), we check if:
     *   `V * (V - 1) == 2 * E`
     * - Count and return the number of complete components.
     *
     * Complexity Analysis:
     * - **Time Complexity**: O(V + E), where `V` is the number of nodes and `E` is the number of edges.
     * - **Space Complexity**: O(V + E) for the adjacency list and visited array.
     */
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        // Build adjacency list
        for (auto& e : edges)
        {
            int from = e[0], to = e[1];
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                // connectedComponentInfo[0] = number of vertices, connectedComponentInfo[1] = total edges count
                vector<int> connectedComponentInfo(2, 0);
                dfs(adjList, visited, i, connectedComponentInfo);

                // Each edge is counted twice, so actual edge count is connectedComponentInfo[1] / 2
                if (connectedComponentInfo[0] * (connectedComponentInfo[0] - 1) == connectedComponentInfo[1])
                    ++count;
            }
        }
        
        return count;
    }

private:
    /**
     * Perform DFS to find all nodes in the connected component
     * and track the number of nodes and edges.
     */
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node, vector<int>& connectedComponentInfo)
    {
        visited[node] = true;
        ++connectedComponentInfo[0];              // Count nodes
        connectedComponentInfo[1] += adjList[node].size(); // Count edges (each counted twice)

        for (int neighbour : adjList[node])
        {
            if (!visited[neighbour])
                dfs(adjList, visited, neighbour, connectedComponentInfo);
        }
    }
};