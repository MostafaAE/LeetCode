### Approach:
- Perform a reverse in-order traversal (right, root, left) of the tree.
- Maintain a running sum of the nodes visited so far, and update each node's value to this running sum.
- The reverse in-order traversal ensures that we visit nodes in descending order.
​
### Complexity:
- **Time Complexity: `O(n)`**, where n is the number of nodes in the tree.
- **Space Complexity: `O(h)`**, where h is the height of the tree. Auxiliary space for stack `h` could be `(n)` or `(logn)` depending on the shape of the tree