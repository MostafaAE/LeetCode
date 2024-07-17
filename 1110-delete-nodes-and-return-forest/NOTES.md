### Approach:
- Convert the `to_delete` list into an unordered_set for O(1) average-time complexity checks.
- Use a recursive function to traverse the tree and delete nodes as specified.
- Maintain an unordered_map to keep track of current roots of the remaining trees.
- If a node needs to be deleted:
- Remove it from the map if it is a root.
- Add its children to the map as new roots if they are not null.
- Recursively delete the node's children.
- If a node does not need to be deleted:
- Recursively process its left and right children.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**