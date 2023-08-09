const int N = 9;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(0, board);
    }
    
    bool solve(int cell, vector<vector<char>> &board)
    {
        // finished the board
        if(cell == N*N)
            return true;
        
        int r = cell / N;
        int c = cell % N;
        
        if(board[r][c] != '.')
            return solve(cell + 1, board);
        
        for(char d = '1' ; d <= '9' ; d++)
        {
            if(!valid(r,c, d,board))
                continue;

            board[r][c] = d;
            if(solve(cell + 1, board))
                return true;
            board[r][c] = '.';
        }
        
        return false;
    }
    
    /* 
    * Approach:
    * validate row , col and sub-box does not have this digit
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool valid(int r, int c, char d, vector<vector<char>>& board) 
    {
        // validate row and column
        for(int i = 0 ; i < N ; i++)
        {
            if(board[r][i] != '.' && board[r][i] == d)
                return false;

            if(board[i][c] != '.' && board[i][c] == d)
                return false;
        }
        
        
        // validate sub-box
        int i = r / 3, j = c / 3;
        for(int r = 0 ; r < 3 ; r++)
        {
            for(int c = 0 ; c < 3 ; c++)
            {
                char cur = board[i*3+r][j*3+c];
                if(cur != '.' && cur == d)
                    return false;
            }
        }

        return true;
    }
};