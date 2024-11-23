### Approach:
1. **Simulate Gravity**:
- Iterate over each row in the `box` from right to left.
- Stones (`#`) fall to the lowest available position (tracked by `lowestColWithEmptyCell`).
- When an obstacle (`*`) is encountered, reset `lowestColWithEmptyCell` to just before the obstacle.
2. **Rotate the Box**:
- Create a new 2D vector `rotatedBox` with dimensions `cols x rows`.
- Map each cell in the `box` to its new position in `rotatedBox` such that the box is rotated 90° clockwise.
​
### Complexity:
- **Time Complexity: `O(m * n)`**
- **Space Complexity: `O(m * n)`**