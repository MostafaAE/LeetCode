class Solution {
private:
    // Directions for moving up, down, left, and right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    /**
     * Approach:
     * - Identify connected components and their sizes using DFS.
     * - For each `0`, simulate flipping it to `1` and calculate the resulting island size.
     *
     * Complexity:
     * - Time: O(n^2), where n is the size of the grid.
     * - Space: O(n^2) for tracking components and their sizes.
     */
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        // Map to store size of each connected component
        unordered_map<int, int> connectedComponentLen;

        // Matrix to track which component each cell belongs to
        vector<vector<int>> cellToConnectedComponentIdx(n, vector<int>(n, -1));

        int groupIdx = 0;

        // Step 1: Identify connected components and calculate their sizes
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j] == 1 && cellToConnectedComponentIdx[i][j] == -1) 
                {
                    dfs(grid, i, j, cellToConnectedComponentIdx, connectedComponentLen, groupIdx);
                    ++groupIdx; // Move to the next group
                }
            }
        }

        // Step 2: Find the largest component size without flipping
        int result = 0;
        for (auto& [group, len] : connectedComponentLen)
            result = max(result, len);

        // Step 3: Evaluate the impact of flipping each `0` to `1`
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j] == 0) 
                {
                    unordered_set<int> hashSet;

                    // Check all 4 neighbors
                    for (int d = 0; d < 4; ++d) 
                    {
                        int nr = i + dr[d], nc = j + dc[d];
                        if (isValid(grid, nr, nc) && grid[nr][nc] == 1) 
                            hashSet.insert(cellToConnectedComponentIdx[nr][nc]);
                    }

                    // Calculate the potential new island size
                    int currentIslandLen = 1; // Include the flipped cell
                    for (int groupIdx : hashSet)
                        currentIslandLen += connectedComponentLen[groupIdx];

                    result = max(result, currentIslandLen);
                }
            }
        }

        return result;
    }

private:
    /**
     * Performs DFS to calculate the size of a connected component and assigns group indices.
     */
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& cellToConnectedComponentIdx, unordered_map<int, int>& connectedComponentLen, int groupIdx) 
    {
        cellToConnectedComponentIdx[row][col] = groupIdx;
        ++connectedComponentLen[groupIdx];

        for (int i = 0; i < 4; ++i) 
        {
            int nr = row + dr[i], nc = col + dc[i];
            if (isValid(grid, nr, nc) && grid[nr][nc] == 1 && cellToConnectedComponentIdx[nr][nc] == -1)
                dfs(grid, nr, nc, cellToConnectedComponentIdx, connectedComponentLen, groupIdx);
        }
    }

    /**
     * Checks if a cell is within grid boundaries.
     */
    bool isValid(vector<vector<int>>& grid, int row, int col) 
    {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid.size();
    }
};
