### Approach:
Iterate over the intervals array
- if the current interval comes before the new interval, then insert it in results
- if the current interval comes after the new interval, then insert the new interval and rest of intervals
- if the current inerval's end overlap with the new interval, then stretch the start of the new interval
- if the current interval's start overlap with the new interval, then stretch the end of the new interval
- if the current interval completely overlap the new interval, then make the new interval = cur interval
​
### Complexity:
**Time Complexity: O(n)**\
**Space Complexity: O(1)** *=> ignoring the output space*