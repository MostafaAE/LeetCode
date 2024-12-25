### Approach:
1. Use a level-order traversal (BFS) to traverse the binary tree level by level.
2. At each level:
- Find the maximum value among the nodes.
- Add the maximum value to the result vector.
3. Return the result vector after processing all levels.
​
### Complexity:
- **Time Complexity: `O(n)`** - Each node in the tree is visited exactly once during the traversal.
- **Space Complexity: `O(w)`** - The queue can hold at most `w` nodes, where `w` is the maximum width of the tree.