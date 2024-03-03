### Approach:
Use two pointers (left, right), where one of them ahead of the other by n nodes (right), then move both till the advancing pointer reaches the end (right), now we have the node preceding the node to be deleted (left).\
Get the size on the linkedlist, then remove the nth node from the end.\
We can also solve it in one pass by storing all the nodes in a vector then remove the target node but will be O(n) memory.
​
### Complexity:
**Time Complexity: O(n)**\
**Space Complexity: O(1)**