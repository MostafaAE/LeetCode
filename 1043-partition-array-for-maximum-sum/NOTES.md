### Approach:
Dynamic Programming Memoization.
​
Direct Consecutive range pattern\
We want to find a good array split
​
dp(idx)\
Try all consecutive ranges as long as subarrays length < k
​
​
### Complexity:
**Time Complexity: `O(N^2)`**\
**Space Complexity: `O(N)`** *where N is the max index*