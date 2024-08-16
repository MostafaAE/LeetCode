### Approach:
- Initialize `minSoFar` and `maxSoFar` with the first array's minimum and maximum elements.
- Iterate through the remaining arrays and calculate the maximum distance by comparing:
- The difference between the current `maxSoFar` and the first element of the current array.
- The difference between the last element of the current array and `minSoFar`.
- Update `minSoFar` and `maxSoFar` accordingly.
- The result will be the maximum distance found during the iteration.
​
### Complexity:
- **Time Complexity: `O(m)`**, where n is the number of arrays.
- **Space Complexity: `O(1)`**