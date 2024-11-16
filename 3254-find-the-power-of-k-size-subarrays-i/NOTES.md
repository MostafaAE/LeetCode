### Approach:
1. Use a sliding window technique to process the `nums` array with a window of size `k`.
2. Maintain indices `left` and `right` to represent the window's boundaries.
3. Track the `lastNonConsecutiveIdx` where a non-consecutive number was found within the window.
- If the difference between `nums[right]` and `nums[right-1]` is not 1, update `lastIdx` to `right`.
4. For each window:
- If the window is valid (no non-consecutive numbers from `left` to `right`), add `nums[right]` to the result.
- Otherwise, add `-1` to the result.
5. Slide the window by incrementing both `left` and `right`.
​
### Complexity:
- **Time Complexity: `O(n)`**, where n is the size of the `nums` array.
- **Space Complexity: `O(1)`**