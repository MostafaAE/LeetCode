### Approach:
- Traverse the linked list starting from the node after the dummy head.
- For each segment of nodes between two zeroes, sum their values.
- Update the value of the first node of the segment with the sum.
- Link this node to the next segment's starting node.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**