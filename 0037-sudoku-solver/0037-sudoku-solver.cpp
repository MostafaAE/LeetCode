class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(0, 0, board);
    }
    
    bool solve(int r, int c, vector<vector<char>> &board)
    {
        
        if(r == (int)board.size())
            return true;
        
        int nextR = r + ((c + 1) / 9);
        int nextC = (c + 1) % 9;
        

        if(board[r][c] == '.')
        {
            for(char i = '1' ; i <= '9' ; i++)
            {
                board[r][c] = i;
                
                if(!valid(r,c, board))
                    continue;
                
                if(solve(nextR, nextC, board))
                    return true;
            }
            board[r][c] = '.';
        }
        
        else
            return solve(nextR, nextC, board);
        
        return false;
    }
    
    /* 
    * Approach:
    * use a hashmap to validate row , col and sub-box does not have any duplicates
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool valid(int r, int c, vector<vector<char>>& board) 
    {
        // validate row and column
        unordered_set<char> row;
        unordered_set<char> col;
        for(int i = 0 ; i < 9 ; i++)
        {
            if(board[r][i] != '.' && !row.insert(board[r][i]).second)
                return false;

            if(board[i][c] != '.' && !col.insert(board[i][c]).second)
                return false;
        }
        
        
        // validate sub-box
        unordered_set<char> box;
        int i = r / 3, j = c / 3;
        for(int r = 0 ; r < 3 ; r++)
        {
            for(int c = 0 ; c < 3 ; c++)
            {
                char cur = board[i*3+r][j*3+c];
                if(cur != '.' && !box.insert(cur).second)
                    return false;
            }
        }

        return true;
    }
};