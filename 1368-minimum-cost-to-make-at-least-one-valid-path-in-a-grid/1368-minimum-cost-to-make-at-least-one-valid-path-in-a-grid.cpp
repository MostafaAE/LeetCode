struct cell {
    int row;
    int col;
    int cost;

    bool operator<(const cell &e) const
	{
		return cost > e.cost;
	}
};

class Solution {
private:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
public:
    int minCost(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> len(m, vector<int>(n, INT_MAX));

        priority_queue<cell> heap;

        heap.push({0, 0, 0});

        int result{INT_MAX};
        while(!heap.empty())
        {
            auto [row, col, cost] = heap.top();
            heap.pop();

            if(row == m-1 && col == n-1)
            {
                result = min(result, cost);
                continue;
            }

            for(int i = 0 ; i < 4 ; ++i)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                if(!isValid(nr, nc, grid))
                    continue;
                
                int newCost = cost + (grid[row][col] == (i + 1) ? 0 : 1);
                if(len[nr][nc] > newCost)
                {
                    heap.push({nr, nc, newCost});
                    len[nr][nc] = newCost;
                }
            }
        }

        return result;
    }

    bool isValid(int r, int c, vector<vector<int>>& grid)
    {
        if(r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0)
            return false;
        
        return true;
    }
};

// (1, 1) => 1
// (1, 2) => 1
// (1, 3) => 1
// (2, 0) => 2
// (1, 1) => 2