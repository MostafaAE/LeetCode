### Approach:
- To maximize the score for a sightseeing pair `values[i] + values[j] + i - j` (where `i < j`):
- Iterate from the end of the array to the beginning.
- Maintain `maxFromSubtract = max(values[j] - j)` as you traverse.
- At each step, compute the potential score using `values[i-1] + (i-1) + maxFromSubtract`.
- Update the result if the computed score is greater than the current maximum.
​
### Complexity:
- **Time Complexity: `O(n)`**, where `n` is the size of the input array.
- **Space Complexity: `O(1)`**, since no additional space is used.