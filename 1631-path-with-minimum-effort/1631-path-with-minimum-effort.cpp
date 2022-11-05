class Solution {
private:
// direction arrays
// delta for: up, down, left, right
int dr[4]{-1, 1, 0 , 0};
int dc[4]{0, 0, -1 , 1};
public:
    
    /* 
    * Approach:
    * Consider the grid as a graph, where adjacent cells have an edge with cost
    * of the difference between the cells, then apply binary search to find the
    * minimum possible value (k) to go from (0, 0) to (n-1, m-1) using only edges of ≤ k cost
    */
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = (int)heights.size(), n = (int)heights[0].size();
        
        int start = 0, end = 1e6, answer = end;
        
        while(start <= end)
        {
            vector<vector<bool>> visited(m, vector<bool>(n));

            int mid = start + (end - start) / 2;
            bool possible = dfs(heights, 0, 0, visited, mid);
            
            if(possible)
                end = mid - 1, answer = mid;
            else
                start = mid + 1;
        }
        
        return answer;
    }
    
    bool dfs(vector<vector<int>>& graph, int r, int c, vector<vector<bool>>& visited, int k)
    {
        bool possible{false};
        
        if((r == (int)graph.size()-1 && c == (int)graph[0].size()-1))
            return true;
        
        visited[r][c] = 1;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if(isValid(nr, nc, graph) && !visited[nr][nc] && abs(graph[r][c] - graph[nr][nc]) <= k)
                possible |= dfs(graph, nr, nc, visited, k); 
        }
        
        return possible;
    }
    
    // return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, vector<vector<int>>& graph)
    {
        if(nr < 0 || nr >= (int)graph.size() || nc < 0 || nc >= (int)graph[0].size())
            return false;
        return true;
    }
};