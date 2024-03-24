### Approach:
This is a variant of Linked List Cycle II Problem\
Use a slow and fast pointer to find the intersection point (where they meet), then move the head and the intersection 1 step until they meet. O(n) time & O(1) memory, without modifying the array `nums`\
​
Another solution: Iterate over nums, for each value we find mark it as found by multiplying the value in its index by -1. O(n) time and O(1) memory but modifies the array.\
​
Another solution: Use a hash table to check if a number is repeated. O(n) time and memory.\
​
### Complexity:
**Time Complexity: O(n)**\
**Space Complexity: O(1)**