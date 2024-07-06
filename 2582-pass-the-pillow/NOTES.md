### Approach:
- Determine the direction of the pillow based on how many full passes (n-1 steps) have been made.
- If the number of full passes is even, the pillow is moving forward.
- If the number of full passes is odd, the pillow is moving backward.
- Calculate the current position of the pillow based on the remainder of the time divided by (n-1).
- Adjust the index accordingly based on the direction.
​
### Complexity:
- **Time Complexity: `O(1)`**
- **Space Complexity: `O(1)`**