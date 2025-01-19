class Solution {
private:
    struct cell {
        int height;
        int row;
        int col;

        // Ensure min-heap by overriding operator<
        bool operator<(const cell& c) const {
            return height > c.height;
        }
    };

    // Directions for neighboring cells
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int m = heightMap.size(), n = heightMap[0].size();

        if (m <= 1 || n <= 1) return 0;
        
        priority_queue<cell> pq;

        // Mark boundaries and add them to the priority queue
        for (int c = 0; c < n; ++c) 
        {
            pq.push({heightMap[0][c], 0, c});
            pq.push({heightMap[m - 1][c], m - 1, c});
            heightMap[0][c] = heightMap[m - 1][c] = -1;
        }

        for (int r = 0; r < m; ++r) 
        {
            pq.push({heightMap[r][0], r, 0});
            pq.push({heightMap[r][n - 1], r, n - 1});
            heightMap[r][0] = heightMap[r][n - 1] = -1;
        }

        int maxSoFar = 0, result = 0;

        // Process cells in increasing height order
        while (!pq.empty()) 
        {
            auto [height, row, col] = pq.top();
            pq.pop();

            maxSoFar = max(maxSoFar, height);

            // Check neighboring cells
            for (int i = 0; i < 4; ++i) 
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && heightMap[nr][nc] != -1) 
                {
                    result += max(0, maxSoFar - heightMap[nr][nc]);
                    pq.push({heightMap[nr][nc], nr, nc});
                    heightMap[nr][nc] = -1;
                }
            }
        }

        return result;
    }
};
