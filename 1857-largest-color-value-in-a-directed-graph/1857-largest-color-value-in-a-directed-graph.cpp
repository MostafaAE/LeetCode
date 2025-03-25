class Solution {
public:
    /**
     * Approach:
     * - This problem is a **Graph Coloring + Topological Sorting (Kahn's Algorithm)** problem.
     * - We detect cycles using **topological sorting**.
     * - We track the **maximum frequency of colors** along any valid path in the graph.
     * - If a cycle exists (not all nodes are visited in topological sorting), return `-1`.
     * - Otherwise, return the **maximum occurrence of any color** across all paths.
     *
     * Complexity Analysis:
     * - **Overall Time Complexity**: **O(N + E)**
     *      - **Building the graph** takes **O(N + E)**.
     *      - **Topological Sorting (Kahn's Algorithm)** takes **O(N + E)**.
     *      - **Updating color frequencies** takes **O(26 * (N + E)) ≈ O(N + E)** since there are at most 26 colors.
     * - **Space Complexity**: **O(N + E)** (for adjacency list, indegree array, and color frequency tracking).
     */
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n = colors.size(), visitedNodes = 0;
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);
        vector<vector<int>> colorCount(n, vector<int>(26, 0)); // Frequency of each color per node

        // Step 1: Build adjacency list and indegree array
        for (auto& e : edges)
        {
            int from = e[0], to = e[1];
            adjList[from].push_back(to);
            ++indegree[to];
        }

        // Step 2: Push all nodes with zero indegree into the queue (no prerequisites)
        queue<int> ready;
        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0)
                ready.push(i);
        }

        int maxColorValue = 0;

        // Step 3: Process nodes in topological order
        while (!ready.empty())
        {
            int cur = ready.front();
            ready.pop();
            ++visitedNodes;

            // Increment color frequency for current node's color
            int colorIdx = colors[cur] - 'a';
            colorCount[cur][colorIdx]++;
            maxColorValue = max(maxColorValue, colorCount[cur][colorIdx]);

            for (int neighbour : adjList[cur])
            {
                // Update color count for the neighbor based on the current node
                for (int c = 0; c < 26; ++c)
                {
                    colorCount[neighbour][c] = max(colorCount[neighbour][c], colorCount[cur][c]);
                }

                // Reduce indegree and add to queue if no dependencies remain
                if (--indegree[neighbour] == 0)
                {
                    ready.push(neighbour);
                }
            }
        }

        // Step 4: Cycle detection - If not all nodes were visited, return -1
        if (visitedNodes != n)
            return -1;

        return maxColorValue;
    }
};
