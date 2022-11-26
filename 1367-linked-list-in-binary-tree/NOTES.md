### Approach:
Iterate over the tree using DFS checking if all the elements in the linked list starting from the head correspond to some downward path in the binary tree.
​
### Complexity:
**Time Complexity: O(n * min(L,h))** where L is the list length and h is the tree height
**Space Complexity: O(h)** => auxiliary space for stack
h could be (n) or (logn) depending on the shape of the tree