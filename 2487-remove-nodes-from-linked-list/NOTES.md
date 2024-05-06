### Approach:
- Recursively traverse the linked list from head to tail.
- While traversing back from tail to head, compare the current node's value with the value of the next node.
- If the current node's value is less than the next node's value, remove the current node.
​
### Complexity:
- **Time Complexity: `O(n)`**, where n is the number of nodes in the linked list.
- **Space Complexity: `O(n)`**, auxiliary for the recursive function calls.