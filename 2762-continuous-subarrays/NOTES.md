### Approach:
1. Use a sliding window approach to count all valid subarrays where the difference betweenthe maximum and minimum elements in the current window is ≤ 2.
2. Maintain two heaps:
- `maxHeap` to track the maximum value in the current window.
- `minHeap` to track the minimum value in the current window.
3. Expand the window by incrementing `right`, pushing the index into both heaps.
4. If the difference between the maximum and minimum elements in the window exceeds 2:
- Shrink the window by incrementing `left`.
- Remove indices from the heaps that fall outside the window.
5. For every valid window, add `(right - left + 1)` to the result, which is the number of subarrays ending at `right`.
6. Continue until `right` traverses the entire array.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(n)`**