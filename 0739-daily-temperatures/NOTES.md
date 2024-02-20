### Approach:
Use a monotonic decreasing stack for temperatures, when we find a warmer temperature than any in the stack, store the distance between them.
​
### Complexity:
**Time Complexity: O(n)** => iterating on elements ~twice only\
**Space Complexity: O(n)**