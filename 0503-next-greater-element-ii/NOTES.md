### Approach:
Use a monotonic decreasing stack for numbers, when we find a greater number than any in the stack, store it as the next greater number (iterate two times).
​
### Complexity:
**Time Complexity: O(n)** => iterating on elements ~twice only\
**Space Complexity: O(n)**