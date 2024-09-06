### Approach:
- Create an unordered set from the `nums` vector to allow O(1) look-up for the values to be removed.
- Traverse the linked list using two pointers: `cur` (current node) and `prev` (previous node).
- If the value of the current node exists in the set, adjust the pointers to skip the node and delete it.
- If the value does not exist in the set, move both pointers to the next node.
- Return the modified head of the list.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, where `n` is the number of nodes in the linked list and `m` is the size of the `nums` vector.
- **Space Complexity: `O(m)`**