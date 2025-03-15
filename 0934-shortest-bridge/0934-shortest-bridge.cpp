class Solution {
private:
    // Direction vectors for moving up, down, left, right
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1 , 1};

public:
    /**
     * Approach:
     * - Find the first island using DFS/BFS and mark all its positions.
     * - Use BFS from the first island to expand and find the shortest path to the second island.
     * - Each level in BFS represents one step in the bridge-building process.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n²), where `n` is the grid size.
     *   - **Finding the first island**: O(n²) in the worst case.
     *   - **BFS traversal**: O(n²) in the worst case (expanding from one island to another).
     * - **Space Complexity**: O(n²) for the `visited` array and BFS queue.
     */
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n = (int)grid.size();
        queue<pair<int, int>> q; // Queue for BFS expansion
        vector<vector<bool>> visited(n, vector<bool>(n));

        // Find the first island and mark all its positions
        for(int i = 0 ; i < n && q.empty() ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j]) 
                {
                    getConnectedIsland(grid, i, j, q, visited);
                    break;
                }
            }
        }

        // BFS to find the shortest bridge to the second island
        int level = 0;
        while(!q.empty()) 
        {
            int sz = q.size();
            while(sz--) 
            {
                auto [row, col] = q.front();
                q.pop();

                for(int d = 0 ; d < 4 ; d++) {
                    int nr = row + dr[d], nc = col + dc[d];

                    if(isValid(nr, nc, grid) && !visited[nr][nc]) 
                    {
                        // If we reach the second island, return the current level
                        if(grid[nr][nc])
                            return level;
                        else 
                        {
                            q.push({nr, nc});
                            visited[nr][nc] = true; // Mark as visited
                        }
                    }
                }
            }
            level++; // Increment level to track bridge length
        }
        return 0; // This should never be reached as two islands always exist
    }

private:
    /**
     * Identifies all connected cells of the first island and marks them as visited.
     * Adds them to the BFS queue for expansion.
     * 
     * Time Complexity: O(n²) in the worst case.
     * Space Complexity: O(n²) for the queue and visited array.
     */
    void getConnectedIsland(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& island, vector<vector<bool>>& visited) 
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        island.push({r, c});
        visited[r][c] = true;

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(int d = 0 ; d < 4 ; d++) 
            {
                int nr = row + dr[d], nc = col + dc[d];

                if(isValid(nr, nc, grid) && !visited[nr][nc] && grid[nr][nc]) 
                {
                    q.push({nr, nc});
                    island.push({nr, nc});
                    visited[nr][nc] = true; // Mark as visited
                }
            }
        }
    }

    /**
     * Checks if a position (nr, nc) is within grid bounds.
     */
    bool isValid(int nr, int nc, vector<vector<int>>& grid) 
    {
        return (nr >= 0 && nr < (int)grid.size() && nc >= 0 && nc < (int)grid.size());
    }
};