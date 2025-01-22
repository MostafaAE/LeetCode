class Solution {
private:
    // Direction vectors for traversing up, down, left, and right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
public:
    /**
     * Approach:
     * - Use a multi-source BFS to calculate the distance of each cell from the nearest water cell.
     * - Initialize the queue with all water cells and set their height to 0.
     * - For each cell, propagate its height + 1 to its unvisited neighbors.
     * - Repeat until all cells are processed.
     * 
     * Complexity:
     * - Time: O(m * n), where m and n are the dimensions of the grid.
     *   - Each cell is visited exactly once.
     * - Space: O(m * n).
     *   - For the queue and `map` grid.
     */
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> map(m, vector<int>(n, -1)); // -1 indicates unvisited cells
        queue<pair<int, int>> q;

        // Initialize water cells
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (isWater[i][j]) 
                    map[i][j] = 0, q.push({i, j});

        // Multi-source BFS
        while (!q.empty()) 
        {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) 
            {
                int nr = row + dr[i], nc = col + dc[i];

                // Check if the neighbor is within bounds and unvisited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && map[nr][nc] == -1) 
                {
                    map[nr][nc] = map[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return map;
    }
};
