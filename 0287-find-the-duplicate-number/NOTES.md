### Approach:
Iterate over nums, for each value we find mark it as found by multiplying the value in its index by -1 O(1) memory.\
​
Another solution: Use a slow and fast pointer to find the intersection point (where they meet), then move the head and the intersection 1 step until they meet O(1) memory. (variant of Linked List Cycle II Problem)\
​
Another solution: Use a hash table to check if a number is repeated O(n) memory.
​
### Complexity:
**Time Complexity: O(n)**\
**Space Complexity: O(1)**