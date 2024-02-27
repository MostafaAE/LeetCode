### Approach:
Robert W. Floyd's tortoise and hare algorithm: move two pointers at different speeds through the sequence of values, if they met at some point then there is a cycle. otherwise, the fast pointer will reach the end of the list (null).
​
### Complexity:
**Time Complexity: O(n)**\
**Space Complexity: O(1)**