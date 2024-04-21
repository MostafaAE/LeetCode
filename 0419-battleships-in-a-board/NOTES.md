### Approach:
- Iterate through the board. Count a battleship when encountering an 'X' cell, but only if it's not part of another battleship.
- A cell is considered part of another battleship if either the cell to its left or the cell above it is also 'X'. This ensures that each battleship is counted only once.
​
### Complexity:
- **Time Complexity: `O(m * n)`**
- **Space Complexity: `O(1)`**