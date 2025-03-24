typedef vector<vector<int>> GRAPH;

class Solution {
public:
    /**
     * Approach:
     * - Like topological sort but graph is undirected, the focus on in-degree = 1 
     * and we will stop when there are nodes <= 2
     *
     * - How many MHTs can a graph have at most? only 1 if n is odd and 2 if n is even
     *
     * - **Graph Representation**: Construct an adjacency list using `GRAPH graph(n)`.
     * - **Degree Tracking**: Maintain an `indegree` array to count the number of connections for each node.
     * - **Topological Trimming (BFS)**:
     *   - Start with all leaf nodes (`indegree[i] == 1`).
     *   - Repeatedly remove leaves, updating their neighbors' degrees.
     *   - Stop when at most **two nodes** remain (the potential roots).
     *
     * Complexity Analysis:
     * - **Time Complexity**: O(N), as every node and edge is processed once.
     * - **Space Complexity**: O(N), for the graph representation and additional data structures.
     */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if (n == 1) // Special case: only one node
            return {0};

        GRAPH graph(n);
        vector<int> indegree(n, 0);
        vector<int> result;

        // Build the undirected graph
        for (auto& edge : edges)
        {
            addUndirectedEdge(graph, edge[0], edge[1]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        
        queue<int> leaves;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 1)  // Leaf nodes
                leaves.push(i);
        
        int remainingNodes = n;
        
        // Trim leaves level by level until at most two nodes remain
        while (remainingNodes > 2)
        {
            int sz = leaves.size();
            remainingNodes -= sz;

            while (sz--)
            {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : graph[leaf])
                {
                    if (--indegree[neighbor] == 1) // a leaf
                        leaves.push(neighbor);
                }
            }
        }
        
        // Remaining nodes are the centroids (MHT roots)
        while (!leaves.empty())
        {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }

private:
    void addUndirectedEdge(GRAPH& graph, int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
};
