class Solution {
public:
    /**
     * Approach:
     * - Model the graph as an **adjacency list**.
     * - Use **DFS** to find all connected components.
     * - For each connected component, check if it is a **complete graph**:
     *   - In a complete graph of `k` nodes, each node should have exactly `k-1` edges.
     *   - Validate this condition for all nodes in the component.
     * - Count the number of such complete components.
     *
     * Complexity Analysis:
     * - **Time Complexity**: O(V + E), where `V` is the number of nodes and `E` is the number of edges.
     *   - We traverse each node and edge **once** using DFS.
     * - **Space Complexity**: O(V + E), for adjacency list, visited array, and recursion stack.
     */
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        vector<int> indegree(n, 0);

        // Build adjacency list and count in-degrees
        for (auto& e : edges)
        {
            int from = e[0], to = e[1];
            adjList[from].push_back(to);
            adjList[to].push_back(from);
            ++indegree[from];
            ++indegree[to];
        }

        int count = 0;
        // Explore each component using DFS
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                vector<int> connectedComponent;
                dfs(adjList, visited, i, connectedComponent);
                count += isCompleteConnectedComponent(connectedComponent, indegree);
            }
        }
        
        return count;
    }

private:
    /**
     * Perform DFS to find all nodes in the connected component.
     */
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node, vector<int>& connectedComponent)
    {
        visited[node] = true;
        connectedComponent.push_back(node);

        for (int neighbour : adjList[node])
        {
            if (!visited[neighbour])
                dfs(adjList, visited, neighbour, connectedComponent);
        }
    }

    /**
     * Check if the connected component forms a complete graph.
     */
    bool isCompleteConnectedComponent(vector<int>& connectedComponent, vector<int>& indegree)
    {
        int expectedInorderCount = connectedComponent.size() - 1;

        for (int node : connectedComponent)
        {
            if (indegree[node] != expectedInorderCount)
                return false;
        }

        return true;
    }
};
