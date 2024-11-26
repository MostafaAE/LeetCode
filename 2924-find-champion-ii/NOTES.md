### Approach:
1. Create an `indegree` array to count incoming edges for each node.
2. Traverse the `edges` and update the `indegree` for the destination node of each edge.
3. Find the node with `indegree` equal to `0`:
- If more than one node has `indegree == 0`, return `-1` (no unique champion).
- Otherwise, return the node index as the champion.
​
### Complexity:
- **Time Complexity: `O(n + m)`**
- **Space Complexity: `O(n)`**