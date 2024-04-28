### Approach:
Simulate asteroid collisions using a stack.
Iterate through the asteroids, and for each asteroid:
- If it's a negative asteroid and the top of the stack is positive, check for collision:
- If the top of the stack is larger or equal, destroy the current asteroid.
- If the current asteroid is larger, destroy the top of the stack and continue checking.
- If it's a positive asteroid or there are no collisions, push it onto the stack.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**