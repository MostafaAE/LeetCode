class Solution {
private:
    int dr[4] = {0, 0, 1, -1}; // Direction arrays for row movement
    int dc[4] = {1, -1, 0, 0}; // Direction arrays for column movement

public:
    /**
     * Approach:
     * - Use a 0-1 BFS with a deque to find the minimum cost to reach the bottom-right corner of the grid.
     * - The deque allows us to efficiently prioritize cells with no additional cost (cost = 0) by pushing them to the front, while cells with an additional cost (cost = 1) are pushed to the back.
     * - Maintain a `minCost` array to track the minimum cost to reach each cell.
     * - At each step, explore all four possible directions and update the cost if a better path is found.
     * 
     * Complexity:
     * - Time: O(m * n), where m and n are the dimensions of the grid. Each cell is processed at most once.
     * - Space: O(m * n) for the deque and the `minCost` array.
     */
    int minCost(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();

        // Deque for 0-1 BFS
        deque<pair<int, int>> dq;

        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));

        dq.push_front({0, 0});
        minCost[0][0] = 0;

        while (!dq.empty()) 
        {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; ++i) 
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (!isValid(nr, nc, grid))
                    continue;

                int cost = (grid[row][col] == (i + 1)) ? 0 : 1;

                // Update if the new path is better
                if (minCost[row][col] + cost < minCost[nr][nc]) 
                {
                    minCost[nr][nc] = minCost[row][col] + cost;

                    if (cost == 1)
                        dq.push_back({nr, nc});
                    else
                        dq.push_front({nr, nc});
                }
            }
        }

        return minCost[m - 1][n - 1];
    }

    // Check if a cell is within bounds
    bool isValid(int r, int c, vector<vector<int>>& grid) 
    {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};
