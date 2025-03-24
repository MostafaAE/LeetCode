class Solution {
private:
    // Direction vectors for moving up, down, left, and right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    /**
     * Approach:
     * - **Topological Sorting (Kahn's Algorithm)**:
     *   - Treat the matrix as a **directed graph (DAG)**, where edges point from **smaller values to larger values**.
     *   - Compute **in-degrees**: Each cell gets an in-degree based on how many larger neighbors it has.
     *   - Push **all cells with zero in-degree** into a queue.
     *   - Perform **BFS level-wise traversal**, reducing in-degrees of neighbors.
     *   - The last BFS level gives the length of the **longest increasing path**.
     *
     * Complexity Analysis:
     * - **Time Complexity**: O(M * N), since each cell is processed once in BFS.
     * - **Space Complexity**: O(M * N), for storing `indegree` and BFS queue.
     */
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        queue<pair<int, int>> ready; // Stores cells ready for processing

        // Step 1: Compute in-degree for each cell
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int d = 0; d < 4; d++) // Check 4 directions
                {
                    int nr = i + dr[d], nc = j + dc[d];
                    if (isValid(nr, nc, m, n) && matrix[nr][nc] < matrix[i][j])
                        indegree[i][j]++;
                }
                
                if (indegree[i][j] == 0) // Starting points
                    ready.push({i, j});
            }
        }

        // Step 2: Perform BFS level-wise traversal
        int level = 0;
        while (!ready.empty())
        {
            int sz = ready.size();
            while (sz--)
            {
                auto [r, c] = ready.front();
                ready.pop();

                for (int d = 0; d < 4; d++)
                {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (isValid(nr, nc, m, n) && matrix[nr][nc] > matrix[r][c] && --indegree[nr][nc] == 0)
                        ready.push({nr, nc});
                }
            }
            level++;
        }

        return level;
    }

private:
    // Helper function to check if a cell is within bounds
    bool isValid(int nr, int nc, int m, int n)
    {
        return (nr >= 0 && nr < m && nc >= 0 && nc < n);
    }
};
