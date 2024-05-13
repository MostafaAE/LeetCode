### Approach:
- To maximize the score, we need to ensure that the leftmost column has all 1s.
- Then, we iterate through each column starting from the second column.
- For each column, count the number of 1s. If the number of 0s is greater than the number of 1s, flip the column and add its decimal value to the score.
​
### Complexity:
- **Time Complexity: `O(m*n)`**, where m is the number of rows and n is the number of columns.
- **Space Complexity: `O(1)`**