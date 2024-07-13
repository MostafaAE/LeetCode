### Approach:
- Use a map to store positions and corresponding indices of robots.
- Use a stack to manage robots moving to the right ('R').
- Iterate through robots in the order of their positions.
- For robots moving to the left ('L'), handle collisions with robots in the stack.
- For robots moving to the right ('R'), push their indices onto the stack.
- After processing all robots, collect the healths of surviving robots.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(n)`**