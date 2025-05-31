class Solution {
public:
    /*
     * Approach:
     * - Use Breadth-First Search (BFS) to simulate moving through the board starting from square 1.
     * - The board is transformed from 2D zigzag into a 1D array for easier index calculation.
     * - At each step, try moving 1 to 6 positions ahead and take the ladder or snake if present.
     * - Track the shortest path to each cell using a `len` array.
     *
     * Time Complexity: O(N^2)
     * - At most we visit each of the N*N cells once.
     *
     * Space Complexity: O(N^2)
     * - For the `flattenBoard` and `len` arrays.
     */
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size(), maxSize = n * n;

        // Distance to reach each cell, 1-based indexing
        vector<int> len(maxSize + 1, INT_MAX);

        // Convert zigzag 2D board into 1D board
        vector<int> flattenBoard = flattenZigZagBoard(board);

        queue<int> q;
        q.push(1);
        len[1] = 0;

        int level = 0;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int cur = q.front();
                q.pop();

                // Try moving from cur+1 to cur+6
                for (int next = cur + 1; next <= maxSize && next <= cur + 6; ++next)
                {
                    int destination = (flattenBoard[next] == -1) ? next : flattenBoard[next];

                    // If this cell hasn't been visited yet
                    if (len[destination] == INT_MAX)
                    {
                        len[destination] = level + 1;
                        q.push(destination);
                    }
                }
            }

            ++level;
        }

        return len[maxSize] == INT_MAX ? -1 : len[maxSize];
    }

private:
    // Convert 2D zigzag board into 1D array using 1-based indexing
    vector<int> flattenZigZagBoard(vector<vector<int>>& board)
    {
        int n = board.size(), idx = 1;
        vector<int> flattenBoard(n * n + 1);
        bool leftToRight = true;

        for (int row = n - 1; row >= 0; --row) 
        {
            if (leftToRight) 
            {
                for (int col = 0; col < n; ++col) 
                {
                    flattenBoard[idx++] = board[row][col];
                }
            } 
            else 
            {
                for (int col = n - 1; col >= 0; --col) 
                {
                    flattenBoard[idx++] = board[row][col];
                }
            }

            leftToRight = !leftToRight; // Alternate direction each row
        }

        return flattenBoard;
    }
};