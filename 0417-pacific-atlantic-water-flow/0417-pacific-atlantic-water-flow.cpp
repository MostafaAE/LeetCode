class Solution {
private:
    // Direction vectors for moving up, down, left, and right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    /**
     * Approach:
     * - We use **Breadth-First Search (BFS)** to find all cells that can reach both the Pacific and Atlantic oceans.
     * - Each ocean is treated as a separate BFS traversal starting from its respective borders.
     * - A **boolean visited matrix** is maintained for each ocean to track reachable cells.
     * - If a cell is marked as reachable in both matrices, it is part of the result.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(m × n), since each cell is processed at most twice (once for each ocean).
     * - **Space Complexity**: O(m × n), due to the visited matrices and the BFS queue.
     */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int rows = heights.size(), cols = heights[0].size();
        queue<pair<int, int>> pacificQueue, atlanticQueue;
        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols, false));

        // Initialize BFS from Pacific (left and top edges) and Atlantic (right and bottom edges)
        for (int c = 0; c < cols; ++c) 
        {
            pacificQueue.push({0, c});
            pacificVisited[0][c] = true;
            atlanticQueue.push({rows - 1, c});
            atlanticVisited[rows - 1][c] = true;
        }
        
        for (int r = 0; r < rows; ++r) 
        {
            pacificQueue.push({r, 0});
            pacificVisited[r][0] = true;
            atlanticQueue.push({r, cols - 1});
            atlanticVisited[r][cols - 1] = true;
        }

        // Perform BFS for both oceans
        bfs(pacificQueue, pacificVisited, heights);
        bfs(atlanticQueue, atlanticVisited, heights);

        vector<vector<int>> result;

        // Collect cells that can reach both oceans
        for (int r = 0; r < rows; ++r) 
        {
            for (int c = 0; c < cols; ++c) 
            {
                if (pacificVisited[r][c] && atlanticVisited[r][c]) 
                {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }

private:
    /**
     * Perform BFS traversal to mark all reachable cells for a given ocean.
     */
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited, vector<vector<int>>& heights) 
    {
        while (!q.empty()) 
        {
            int sz = q.size();

            while (sz--) 
            {
                auto [row, col] = q.front();
                q.pop();

                // Explore all 4 possible directions
                for (int d = 0; d < 4; ++d) 
                {
                    int nr = row + dr[d], nc = col + dc[d];

                    // Check if the new cell is within bounds, not visited, and has an equal or greater height
                    if (isValid(heights, nr, nc) && !visited[nr][nc] && heights[nr][nc] >= heights[row][col]) 
                    {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    /**
     * Checks if the given coordinates are within the matrix bounds.
     */
    bool isValid(vector<vector<int>>& heights, int row, int col) 
    {
        return row >= 0 && row < heights.size() && col >= 0 && col < heights[0].size();
    }
};
