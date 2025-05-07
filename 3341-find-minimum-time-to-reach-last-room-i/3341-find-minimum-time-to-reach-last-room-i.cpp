/**
 * Approach:
 * - This problem is modeled as a **shortest path** problem on a 2D grid.
 * - Each cell `(x, y)` has a `moveTime[x][y]`, which means you cannot enter it before this time.
 * - We use **Dijkstra's Algorithm** to find the minimum time required to reach the bottom-right cell from the top-left.
 * - When moving to a neighbor, we wait until the `moveTime` for that cell is reached, then spend 1 unit of time to move in.
 * - The key idea is: at each step, move to the neighbor that offers the smallest **arrival time**, accounting for `moveTime`.

 * Time Complexity: O(N * M * log(N*M))
 * - Each cell is processed once, and up to 4 neighbors are pushed into the priority queue with a logarithmic insertion cost.

 * Space Complexity: O(N * M)
 * - For the distance matrix and visited tracking.
 */

class Solution {
private:
    int dx[4] = {-1, 1, 0, 0};  // Movement directions (up, down, left, right)
    int dy[4] = {0, 0, -1, 1};

    // Custom struct for priority queue (min-heap based on weight)
    struct Edge {
        int x, y, weight;

        Edge(int x, int y, int weight) : x(x), y(y), weight(weight) {}

        bool operator<(const Edge& e) const {
            return weight > e.weight; // min-heap by weight
        }
    };

    // Check if a cell (x, y) is within bounds
    bool isValid(int n, int m, int x, int y) 
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
        int n = moveTime.size(), m = moveTime[0].size(), INF = 2e9;

        vector<vector<int>> dist(n, vector<int>(m, INF));      // Min arrival time
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // Mark visited cells

        priority_queue<Edge> pq; // Min-heap of edges

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) 
        {
            auto [x, y, currTime] = pq.top();
            pq.pop();

            if (visited[x][y])
                continue;

            visited[x][y] = true;

            for (int d = 0; d < 4; ++d) 
            {
                int newX = x + dx[d], newY = y + dy[d];

                if (isValid(n, m, newX, newY)) 
                {
                    // Wait until moveTime[newX][newY] is reached, then spend 1 unit to move
                    int arrival = max(dist[x][y], moveTime[newX][newY]) + 1;

                    if (dist[newX][newY] > arrival) 
                    {
                        dist[newX][newY] = arrival;
                        pq.push({newX, newY, arrival});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};