### Approach:
1. Use a frequency array `count` to track the range increments:
- For each number `num` in `nums`, increment the frequency at `max(0, num - k)`.
- Decrement the frequency at `num + k + 1` (if within bounds) to mark the end of the range.
2. Calculate the prefix sum of the `count` array:
- Traverse the `count` array to compute the cumulative frequency, representing the number of elements in range at each value.
- Track the maximum value of the prefix sum to determine the maximum beauty.
3. Return the maximum beauty found.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, where `m` is the maximum value in `nums`.
- **Space Complexity: `O(m)`**