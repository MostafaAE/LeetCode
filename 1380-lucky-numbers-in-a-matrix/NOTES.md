### Approach:
- Find the minimum value in each row and store it in a vector `minInRow`.
- Find the maximum value in each column and store it in a vector `maxInCol`.
- Iterate through the matrix and check for values that are both the minimum in their row and the maximum in their column. Add such values to the result vector.
- We can also reduce the space complexity to O(1) because there will always be only 1 lucky number.
​
### Complexity:
- **Time Complexity: `O(m* n)`**
- **Space Complexity: `O(m + n)`**