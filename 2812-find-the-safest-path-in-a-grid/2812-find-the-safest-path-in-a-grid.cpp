class Solution {
private:
    // Arrays to represent the four directions: up, down, left, right
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};

public:
    /* 
    * Approach:
    * - Use breadth-first search (BFS) to calculate the minimum manhattan distance for each cell to any thief in the grid.
    * - Binary search on all the possible safeness factors.
    * - Use breadth-first search (BFS) to find a valid path with a safeness factor greater than or equal to the current candidate.
    *
    * Complexity:
    * - Time Complexity: O(n^2 * log(max_distance)), where n is the size of the grid and max_distance is the maximum possible distance.
    *                    The binary search takes O(log(max_distance)), and for each binary search iteration, BFS is performed, which takes O(n^2).
    * - Space Complexity: O(n^2), for the distance matrix and the BFS queue.
    */
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int maxDistance{};
        vector<vector<int>> distance(n, vector<int>(n, -1));
        
        // Calculate the minimum manhattan distance for each cell to any thief in the grid and find the maximum distance
        calculateDistances(grid, distance, maxDistance);
        
        // Binary search on all the possible safeness factors
        int start = 0, end = maxDistance, result{};
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            // Check if the current safeness factor is valid
            if(isValidSafeness(distance, mid))
            {
                result = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        
        return result;
    }
    
    // Check if a safeness factor is valid by performing BFS
    bool isValidSafeness(vector<vector<int>>& distance, int safenessFactor)
    {
        int n = distance.size();
        
        // Check if the start and end points are reachable with the given safeness factor
        if(distance[0][0] < safenessFactor || distance[n - 1][n - 1] < safenessFactor)
            return false;
        
        // Initialize BFS queue and visited array
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        // Breadth-first search to find a valid path
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == n - 1 && c == n - 1) 
                return true; // Valid path found
            
            // Check neighboring cells
            for (int d = 0 ; d < 4 ; ++d) 
            {
                int nr = r + dr[d], nc = c + dc[d];
                // Check if the neighboring cell is valid and unvisited
                if (isValid(nr, nc, n) && !visited[nr][nc] && distance[nr][nc] >= safenessFactor) 
                {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        
        return false; // No valid path found
    }
    
    // Calculate the minimum manhattan distance for each cell to any thief in the grid using BFS
    void calculateDistances(vector<vector<int>>& grid, vector<vector<int>>& dist, int& maxDist)
    {
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                if(grid[i][j])
                    q.push({i, j}), dist[i][j] = 0;
        
        int level{};
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r, c] = q.front();
                q.pop();
                
                for(int d = 0 ; d < 4 ; ++d)
                {
                    int nr = r + dr[d], nc = c + dc[d];
                    if(isValid(nr, nc, n) && dist[nr][nc] == -1)
                    {
                        dist[nr][nc] = level + 1;
                        q.push({nr, nc});
                        maxDist = max(maxDist, level + 1);
                    }
                }
            }
            ++level;
        }
    }
    
    // Helper function to check if a cell is valid (within the grid boundaries)
    bool isValid(int r, int c, int n)
    {
        if(r < 0 || r >= n || c < 0 || c >= n)
            return false;
        return true;
    }
};
