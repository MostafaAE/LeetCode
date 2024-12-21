### Approach:
1. Represent the graph using an adjacency list.
2. Use DFS to compute the sum of values for each subtree modulo `k`.
3. If a subtree's sum modulo `k` is 0, it can form a separate component.
4. Decrement the total number of components whenever a valid subtree is found.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, Building the adjacency list and performing DFS.
- **Space Complexity: `O(n + m)`**, For the adjacency list and recursion stack.