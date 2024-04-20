### Approach:
- Traverse the string character by character and count the number of consecutive characters.
- Whenever a character changes, update the last consecutive count and reset the consecutive count.
- Increment the count of binary substrings whenever the consecutive count is less than or equal to the last consecutive count.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**