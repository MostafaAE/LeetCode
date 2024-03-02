### Approach:
When we square the array it will be partitioned into two sorted arrays (non-increasing from left) and (non-increasing from right), so we can use two pointers to merge these two arrays in O(n).
​
### Complexity:
**Time Complexity: O(n)**\
**Space Complexity: O(1)** *=> ignoring the output space*