### Approach:
- Initialize a result matrix of size rows x cols filled with 0s.
- Set the first column of the result matrix with the values from the rowSum vector.
- Iterate through each column and each row, adjusting the values based on the remaining column sum.
- For each cell, if the remaining column sum is greater than or equal to the cell value, subtract the cell value from the column sum.
- If the remaining column sum is less than the cell value, update the next cell in the same row with the difference, set the current cell value to the remaining column sum, and set the column sum to 0.
​
### Complexity:
- **Time Complexity: `O(m * n)`**
- **Space Complexity: `O(1)`**