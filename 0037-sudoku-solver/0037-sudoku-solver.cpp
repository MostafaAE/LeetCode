const int N = 9;
bool row[N][N]{}, col[N][N]{}, box[3][3][N]{};
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(box, 0, sizeof(box));
        
        // mark initial reserved values
		for (int r = 0; r < 9; r++)
			for (int c = 0; c < 9; c++)
				if (board[r][c] != '.')
					set(board[r][c] - '1', r, c, 1);
        
        solve(0, board);
    }
    
    bool solve(int cell, vector<vector<char>> &board)
    {
        // finished the board
        if(cell >= N*N)
            return true;
        
        int r = cell / N;
        int c = cell % N;
        
        if(board[r][c] != '.')
            return solve(cell + 1, board);
        
        for(char d = 0 ; d < N ; d++)
        {
            if(row[r][d] || col[c][d] || box[r/3][c/3][d])
                continue;
            // if(!valid(r,c, d,board))
            //     continue;

            set(d, r, c, 1);
            board[r][c] = d + '1';
            if(solve(cell + 1, board))
                return true;
            board[r][c] = '.';
            set(d, r, c, 0);
        }
        
        return false;
    }
    

    void set(int d, int r, int c, int value) 
    {
        row[r][d] = col[c][d] = box[r / 3][c / 3][d] = value;
    }
};