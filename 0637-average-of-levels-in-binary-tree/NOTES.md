### Approach:
- Utilize level order traversal (BFS) to compute the average value of each level in the binary tree.
- Use a queue to keep track of nodes at each level. At each level, compute the sum of node values and count the number of nodes. Calculate the average and store it in the result vector.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**