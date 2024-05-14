### Approach:
- Depth-First Search with Backtracking.
- Start from each cell with non-zero gold and perform a Depth-First Search (DFS) with backtracking to explore all possible paths.
- Keep track of the maximum amount of gold collected during the DFS traversal.
​
### Complexity:
- **Time Complexity: `O(m * n * 4^k)`**, where m and n are the dimensions of the grid, and k is the number of cells with gold.
For each cell with gold, we potentially explore four directions (up, down, left, right) in the DFS, and the maximum depth of the DFS traversal can be up to k.
- **Space Complexity: `O(k)`**, due to the recursive stack space used by the DFS algorithm.