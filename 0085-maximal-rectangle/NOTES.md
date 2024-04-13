### Approach:
1. Prefix Sum and Histogram: We first convert the input matrix of characters to a matrix of integers where each cell represents the height of the rectangle. Then, we apply the prefix sum technique on each column, resetting the sum whenever encountering a '0'. This effectively converts the matrix into a histogram representation for each row.
2. Largest Rectangle in Histogram: For each row, we utilize the monotonic stack approach to compute the largest rectangle area in the histogram (Prerequisite: https://leetcode.com/problems/largest-rectangle-in-histogram/).
​
### Complexity:
- **Time Complexity: `O(MN)`**
- **Space Complexity: `O(MN)`** *=> where M is the number of rows, N is the number of columns*