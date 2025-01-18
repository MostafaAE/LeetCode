class Solution {
private:
    // Struct for representing a cell in the grid
    struct cell {
        int row;
        int col;
        int cost;

        // Custom comparator for priority queue
        bool operator<(const cell& other) const {
            return cost > other.cost;
        }
    };

    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

public:
    /**
     * Approach:
     * - Use Dijkstra's algorithm with a priority queue to find the minimum cost path from the top-left to the bottom-right corner.
     * - Each cell in the grid points in one of four directions (1: right, 2: left, 3: down, 4: up). 
     * - If we move in the intended direction, the cost remains the same. Otherwise, add 1 to the cost.
     * - Update the minimum cost for each cell and explore neighboring cells until the target is reached.
     * 
     * Complexity:
     * - Time: O((m * n) * log(m * n)), where m and n are the dimensions of the grid.
     *   * Each cell is processed at most once, and heap operations take O(log(m * n)).
     * - Space: O(m * n) for the min-cost array and priority queue.
     */
    int minCost(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();

        // Min-cost array to store the cost to reach each cell
        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));

        // Priority queue (min-heap) for Dijkstra's algorithm
        priority_queue<cell> heap;

        heap.push({0, 0, 0});
        minCost[0][0] = 0;

        while (!heap.empty()) 
        {
            auto [row, col, cost] = heap.top();
            heap.pop();

            // Ignore outdated costs
            if (minCost[row][col] != cost) 
                continue;

            // Explore all four directions
            for (int i = 0; i < 4; ++i) 
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                // Skip invalid cells
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Calculate the cost to move to the next cell
                int newCost = cost + (grid[row][col] == (i + 1) ? 0 : 1);

                // Update if the new cost is better
                if (minCost[nr][nc] > newCost) 
                {
                    heap.push({nr, nc, newCost});
                    minCost[nr][nc] = newCost;
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner
        return minCost[m - 1][n - 1];
    }
};
