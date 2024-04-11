### Approach:
Monotonic Increasing Stack & Greedy approach (Start from the left and remove the largest k numbers we face)
- Iterate over num, if the current digit is larger than the top of the stack, then put it in the stack.
- If the current digit is smaller, then keep popping elements from the stack until there are no more bigger elements or we removed k elements.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**