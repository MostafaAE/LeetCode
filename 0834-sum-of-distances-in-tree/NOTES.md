### Approach:
- Two DFS traversals.
- First DFS to compute the sum of distances starting from the root, and the number of nodes in each subtree rooted at each node excluding the parent.
- Second DFS to compute the sum of distances for each node in the tree by re-rooting the tree (shifting the root to each node).
- Suppose we shift the root from root 0 to 1.
- We can observe that count[1] nodes got 1 unit closer to new root and n - count[1] nodes got 1 unit away from the new root.
- So, res[1] = res[0] - count[1] + n - count[1]
- i.e, res[new_root] = res[root] - count[new_root] + n - count[new_root]
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**