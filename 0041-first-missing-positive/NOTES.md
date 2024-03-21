### Approach:
1. First, find the min positive integer in the array, if it is > 1, then the answer is 1
2. If the min positive integer = 1, then perform cycle sort
3. Then iterate on the array to find the first value where value != index + 1 (first missing positive)
​
### Complexity:
**Time Complexity: `O(n)`**\
**Space Complexity: `O(1)`**
​