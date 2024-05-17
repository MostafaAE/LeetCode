### Approach:
- Use a depth-first search (DFS) to traverse the binary tree and count the frequency of each value using a hashmap.
- Find the maximum frequency from the map.
- Collect all values with the maximum frequency and return them as the result.
​
### Complexity:
- **Time Complexity: `O(n)`**, where n is the number of nodes in the binary tree.
- **Space Complexity: `O(n)`**, for storing the frequency of each value in the hashmap.