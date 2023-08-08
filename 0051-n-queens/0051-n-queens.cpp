vector<bool> columns, normDiagonal, antiDiagonal;
vector<string> grid;

int n;
class Solution {
public:
    /* 
    * Approach:
    * Backtracking
    * 
    * Complexity:
    * Time Complexity : O(N!)
    * Space Complexity : O(N^2)
    */
    vector<vector<string>> solveNQueens(int n_) 
    {
        n = n_;
        columns = vector<bool>(n);
        normDiagonal = vector<bool>(2 * n - 1);
        antiDiagonal = vector<bool>(2 * n - 1);
        grid = vector<string>(n, string(n, '.'));
        vector<vector<string>> output;
        
        solve(0, output);
        
        return output;
    }
    
    void solve(int r, vector<vector<string>> &output)
    {
        // each row has a queen
        if(r == n)
        {
            output.push_back(grid);
            return;
        }
        
        // try to put a queen in each possible column
        for(int c = 0 ; c < n ; c++)
        {
            int x = r + c;
		    int y = n - 1 + r - c;	// n-1 to convert [0, 2n-1]
            
            if(columns[c] || normDiagonal[y] || antiDiagonal[x])
                continue;

            grid[r][c] = 'Q';
            columns[c] = normDiagonal[y] = antiDiagonal[x] = 1;
            
            solve(r + 1, output);

            columns[c] = normDiagonal[y] = antiDiagonal[x] = 0;
            grid[r][c] = '.';
        }
        
    }
};