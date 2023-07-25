### Approach:
Dynamic Programming Memoization.\
​
Direct Consecutive range pattern
We want to find a good blocks split
​
dp(idx)
Try all consecutive ranges as long as total width <= shelfWidth
For each choice [idx, k] subarray, recurse on the remaining dp(k+1)
The choice cost is the max height in the subarray [idx, k]
​
### Complexity:
**Time Complexity: `O(N^2)`**\
**Space Complexity: `O(N)`** *where N is the max index*