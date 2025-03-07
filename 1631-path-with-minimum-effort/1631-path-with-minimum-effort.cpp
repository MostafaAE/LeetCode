class Solution {
private:
    // Direction vectors for moving up, down, left, and right
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};

public:
    /**
     * Approach:
     * - We use **Binary Search on Answer** to determine the minimum effort required.
     * - The effort is defined as the maximum absolute difference in heights along the path.
     * - We perform a binary search on the effort range [0, 1e6].
     * - For each mid effort value, we check if it's possible to reach the bottom-right cell from the top-left cell using **DFS**:
     *   - If possible, we try a smaller effort (move left in binary search).
     *   - Otherwise, we increase the effort (move right in binary search).
     * - The DFS explores all 4 directions and only moves if the effort constraint is met.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(m * n * log(max_height)).
     *      - **Binary Search**: O(log(max_height)) → max height is at most 1e6.
     *      - **DFS Traversal**: O(m * n) in the worst case.
     * - **Space Complexity**: O(m * n) for the visited array in DFS.
     */
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = (int)heights.size(), n = (int)heights[0].size();
        int start = 0, end = 1e6, answer = end;

        // Binary search for the minimum required effort
        while (start <= end)
        {
            vector<vector<bool>> visited(m, vector<bool>(n));

            int mid = start + (end - start) / 2;
            bool possible = dfs(heights, 0, 0, visited, mid);

            if (possible) // If reachable with `mid` effort, try reducing it
            {
                end = mid - 1;
                answer = mid;
            }
            else // Otherwise, increase the effort limit
            {
                start = mid + 1;
            }
        }

        return answer;
    }

    // Depth-first search to check if reaching (m-1, n-1) is possible with max effort `k`
    bool dfs(vector<vector<int>>& graph, int r, int c, vector<vector<bool>>& visited, int k)
    {
        visited[r][c] = true;

        if (r == (int)graph.size() - 1 && c == (int)graph[0].size() - 1) 
            return true; // Reached destination

        bool possible = false;
        for (int d = 0; d < 4; d++) // Explore all 4 directions
        {
            int nr = r + dr[d], nc = c + dc[d];

            // Move if within bounds, not visited, and satisfies effort constraint
            if (isValid(nr, nc, graph) && !visited[nr][nc] && abs(graph[r][c] - graph[nr][nc]) <= k)
                possible |= dfs(graph, nr, nc, visited, k);
        }

        return possible;
    }

    // Check if the given cell (nr, nc) is within grid bounds
    bool isValid(int nr, int nc, vector<vector<int>>& graph)
    {
        return nr >= 0 && nr < (int)graph.size() && nc >= 0 && nc < (int)graph[0].size();
    }
};
