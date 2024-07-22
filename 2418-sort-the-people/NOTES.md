### Approach:
- Use a map to associate heights with names, sorting by height automatically since map keys are sorted.
- Traverse the map in reverse order to get names in descending order of heights.
- Push each name into the result vector.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(n)`**