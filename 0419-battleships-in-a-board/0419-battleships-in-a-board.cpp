class Solution {
public:
    /*
     * Approach:
     * Iterate through the board. Count a battleship when encountering an 'X' cell,
     * but only if it's not part of another battleship. A cell is considered part of
     * another battleship if either the cell to its left or the cell above it is also 'X'.
     * This ensures that each battleship is counted only once.
     *
     * Complexity:
     * Time Complexity: O(m * n)
     * Space Complexity: O(1)
     */
    int countBattleships(vector<vector<char>>& board) 
    {
        int battleShips{};
        int m = board.size(), n = board[0].size();
        
        for(int r = 0 ; r < m ; r++)
        {
            for(int c = 0 ; c < n ; c++)
            {
                if((c > 0 && board[r][c - 1] == 'X') || (r > 0 && board[r - 1][c] == 'X'))
                    continue;
                if(board[r][c] == 'X')
                    battleShips++;
            }
        }
        
        return battleShips;
    }
};
