### Approach:
Sort points, and for each point we have two cases (greedy)
- case 1: no overlap with last arrow, then throw a new arrow at the end of this point
- case 2: overlap with last arrow, then adjust the point of last arrow to be the minimum of this point and last point ends
​
### Complexity:
**Time Complexity: `O(nlogn)`**\
**Space Complexity: `O(1)`**