class Solution {
public:
    /**
     * Approach:
     * - This problem is solved using **Graph Topological Sorting (Kahn's Algorithm)**.
     * - We first determine the **bounding box** for each color in `targetGrid`.
     * - Construct a **dependency graph** where color A → color B means A must be printed before B.
     * - Perform **topological sorting** to check if a valid printing order exists.
     * - If all colors can be processed in topological order, return `true`; otherwise, return `false` (cycle detected).
     *
     * Complexity Analysis:
     * - **Overall Time Complexity**: **O(R × C)**
     *      - **Finding bounding boxes** takes **O(R × C)**.
     *      - **Building adjacency list** takes **O(R × C)** in the worst case.
     *      - **Topological sorting (Kahn's Algorithm)** takes **O(C)** where C is the number of colors (≤ 60).
     * - **Space Complexity**: **O(C²)** (in the worst case, fully connected color graph).
     */
    bool isPrintable(vector<vector<int>>& targetGrid) 
    {
        int rows = targetGrid.size(), cols = targetGrid[0].size();
        int maxColor = 60 + 1; // Colors are in range [1, 60]

        // Step 1: Determine the bounding box for each color
        vector<int> rMin(maxColor, rows), rMax(maxColor, -1);
        vector<int> cMin(maxColor, cols), cMax(maxColor, -1);

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                int color = targetGrid[r][c];
                rMin[color] = min(rMin[color], r);
                rMax[color] = max(rMax[color], r);
                cMin[color] = min(cMin[color], c);
                cMax[color] = max(cMax[color], c);
            }
        }

        // Step 2: Build the dependency graph
        vector<vector<int>> adjList(maxColor);
        vector<int> indegree(maxColor, 0);

        for (int color = 1; color < maxColor; ++color)
        {
            for (int r = rMin[color]; r <= rMax[color]; ++r)
            {
                for (int c = cMin[color]; c <= cMax[color]; ++c)
                {
                    if (targetGrid[r][c] != color)
                    {
                        adjList[color].push_back(targetGrid[r][c]);
                        ++indegree[targetGrid[r][c]];
                    }
                }
            }
        }

        // Step 3: Check if a valid printing order exists using topological sorting
        return topologicalSort(adjList, indegree, maxColor);
    }

private:
    bool topologicalSort(vector<vector<int>>& graph, vector<int>& indegree, int maxColor)
    {
        int nodesVisited = 0;
        queue<int> ready;

        // Add all colors with no dependencies (indegree == 0) to the queue
        for (int i = 1; i < maxColor; ++i)
        {
            if (indegree[i] == 0)
                ready.push(i);
        }

        while (!ready.empty())
        {
            int cur = ready.front();
            ready.pop();
            ++nodesVisited;

            for (int neighbour : graph[cur])
            {
                if (--indegree[neighbour] == 0)
                    ready.push(neighbour);
            }
        }

        // If we visited all colors, a valid order exists
        return nodesVisited == maxColor - 1;
    }
};
