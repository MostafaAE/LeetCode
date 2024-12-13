### Approach:
1. Use a min-heap (priority queue) to process elements in increasing order of their values.
2. Push all elements of `nums` into the min-heap along with their indices. This ensures the smallest element is always processed first.
3. While the heap is not empty:
- Pop the smallest element (value and index).
- If the index is already marked, skip it.
- Otherwise, add the value to the `score` and mark the current index, its left neighbor (if valid), and its right neighbor (if valid) as "marked."
4. Return the accumulated `score`.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(n)`**