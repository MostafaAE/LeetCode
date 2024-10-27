### Approach:
1. Use dynamic programming with memoization to calculate the number of square submatrices with all 1s.
2. For each cell (i, j), calculate the largest square submatrix ending at that cell using a helper function `countSq`.
- If matrix[i][j] == 0, return 0 (no square can end at this cell).
- Otherwise, the size of the largest square is determined by the minimum square size possible among the cell above, to the left, and the top-left diagonal cell.
- Store and reuse results in `memory` array to avoid redundant calculations.
3. Accumulate results from each cell to get the total number of squares.
​
### Complexity:
- **Time Complexity: `O(n * m)`**, where n and m are the dimensions of the matrix, as each cell is computed once.
- **Space Complexity: `O(n * m)`**, for the memoization array `memory` and the matrix copy.