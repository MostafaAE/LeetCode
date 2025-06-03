const int N = 9;
bool row[N][N]{}, col[N][N]{}, box[3][3][N]{};

class Solution {
public:
    /*
     * Approach:
     * - Use backtracking to fill empty cells.
     * - Use three boolean arrays (`row`, `col`, `box`) to track constraints efficiently:
     *     - row[r][d] = true if digit d exists in row r
     *     - col[c][d] = true if digit d exists in column c
     *     - box[r/3][c/3][d] = true if digit d exists in its 3x3 sub-box
     * - Try each digit from 1–9 in empty cells and backtrack if invalid.
     *
     * Complexity:
     * Time Complexity  : O(9^(n)) — worst case exponential where n is number of empty cells.
     * Space Complexity : O(1) — fixed-size board and constraint arrays (no dynamic memory).
     */

    void solveSudoku(vector<vector<char>>& board) 
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));

        // Initialize constraints based on prefilled digits
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (board[r][c] != '.')
                    set(board[r][c] - '1', r, c, true);
            }
        }

        solve(0, board);
    }

private:
    // Recursive backtracking function
    bool solve(int cell, vector<vector<char>>& board)
    {
        // All cells filled
        if (cell >= N * N)
            return true;

        int r = cell / N;
        int c = cell % N;

        if (board[r][c] != '.')
            return solve(cell + 1, board);

        for (char d = 0; d < N; ++d)
        {
            // Skip if digit already used in row/col/box
            if (row[r][d] || col[c][d] || box[r / 3][c / 3][d])
                continue;

            // Try placing digit
            set(d, r, c, true);
            board[r][c] = d + '1';

            if (solve(cell + 1, board))
                return true;

            // Backtrack
            board[r][c] = '.';
            set(d, r, c, false);
        }

        return false;
    }

    // Helper to update constraint arrays
    void set(int d, int r, int c, bool value) 
    {
        row[r][d] = col[c][d] = box[r / 3][c / 3][d] = value;
    }
};
