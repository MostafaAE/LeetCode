### Approach:
- Check if the size of the original array matches the desired dimensions `m * n`.
- If not, return an empty 2D array.
- Create a 2D vector `result` with dimensions `m x n`.
- Use a single loop to fill the 2D vector by mapping the 1D index to 2D coordinates.
​
### Complexity:
- **Time Complexity: `O(m * n)`**, where `m` is the number of rows and `n` is the number of columns.
- **Space Complexity: `O(1)`**