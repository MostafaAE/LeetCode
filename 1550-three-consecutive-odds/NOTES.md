### Approach:
- Traverse the array and maintain a counter for consecutive odd numbers.
- If the current number is odd, increment the counter.
- If the current number is even, reset the counter to 0.
- If the counter reaches 3, return true.
- If the loop completes without the counter reaching 3, return false.
​
### Complexity:
- **Time Complexity: `O(n)`**, where n is the length of the array.
- **Space Complexity: `O(1)`**