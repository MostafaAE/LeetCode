### Approach:
- Use a stack to store indices of open parentheses.
- Iterate through the string:
- If the current character is '(', push the current length of the result string onto the stack.
- If the current character is ')', pop the top index from the stack and reverse the substring from this index to the current end of the result string.
- If the current character is a regular character, append it to the result string.
- The final result string will have the correct order after processing all parentheses.
​
### Complexity:
- **Time Complexity: `O(n^2)`**
- **Space Complexity: `O(n)`**