### Approach:
- This solution uses Dynamic Programming with Memoization to calculate the number of ways to achieve the target sum by assigning + or - signs to elements.
- A memory table (`memory`) is used to store intermediate results to avoid redundant calculations.
- The range of possible sums is from -totalSum to +totalSum. To handle this, we use an offset (totalSum) to shift all sums into non-negative indices.
​
### Complexity:
- **Time Complexity: `O(n * t)`**, where n is the size of the array and t = 2 * totalSum + 1 is the range of possible sums.
- **Space Complexity: `O(n * t)`**, for the memoization table.