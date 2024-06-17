### Approach:
- Use the two-pointer technique to efficiently find if there are two numbers whose squares sum to c.
- Initialize two pointers: left at 0 and right at sqrt(c).
- Iterate with the while loop:
- Calculate the sum of the squares of the values pointed by left and right.
- If the sum equals c, return true.
- If the sum is less than c, increment the left pointer to increase the sum.
- If the sum is greater than c, decrement the right pointer to decrease the sum.
- If no pair is found by the time left exceeds right, return false.
​
### Complexity:
- **Time Complexity: `O(√c)`**
- **Space Complexity: `O(1)`**