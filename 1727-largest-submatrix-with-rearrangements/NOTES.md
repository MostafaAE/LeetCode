### Approach:
1. Prefix Sum and Histogram: Apply the prefix sum technique on each column, resetting the sum whenever encountering a '0'. This effectively converts the matrix into a histogram representation for each row.
2. Largest Rectangle in Histogram: For each row, sort it in descending order, and compute the largest rectangle area in the histogram.
​
### Complexity:
- **Time Complexity: `O(MNlogN)`**
- **Space Complexity: `O(N)`** *=> where M is the number of rows, N is the number of columns*