class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> output;
        
        solve(0, output, grid, n);
        
        return output;
    }
    
    void solve(int r, vector<vector<string>> &output, vector<string> &grid, int n)
    {
        if(r == n)
        {
            output.push_back(grid);
            return;
        }
        
        for(int c = 0 ; c < n ; c++)
        {
            if(!valid(r, c, grid))
                continue;

            grid[r][c] = 'Q';

            solve(r + 1, output, grid, n);

            grid[r][c] = '.';
        }
        
    }
    
    bool valid(int r, int c, vector<string> &grid)
    {
        int n{(int)grid.size()};
        
        // Check up-left diagonal
        for(int i = r - 1, j = c - 1 ; i >= 0 && j >= 0 ; i--, j--)
            if(grid[i][j] == 'Q')
                return false;
        
        // Check down-right diagonal
        for(int i = r + 1, j = c + 1 ; i < n && j < n ; i++, j++)
            if(grid[i][j] == 'Q')
                return false;
        
        // Check up-right diagonal
        for(int i = r - 1, j = c + 1 ; i >= 0 && j < n ; i--, j++)
            if(grid[i][j] == 'Q')
                return false;
        
        // Check down-left diagonal
        for(int i = r + 1, j = c - 1 ; i < n && j >= 0 ; i++, j--)
            if(grid[i][j] == 'Q')
                return false;
        
        // Check up
        for(int i = r - 1 ; i >= 0 ; i--)
            if(grid[i][c] == 'Q')
                return false;
        
        // Check down
        for(int i = r + 1 ; i < n; i++)
            if(grid[i][c] == 'Q')
                return false;
        
        return true;
    }
};