### Approach:
- Utilize a hash set, and for each element 'num', check if its negation (-num) exists in the hash set.
- If it exists, update the result to the maximum of the absolute value of 'num' and the current result.
- Return the result, or -1 if no such pair exists.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**