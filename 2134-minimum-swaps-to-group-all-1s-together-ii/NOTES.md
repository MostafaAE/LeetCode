### Approach:
- Count the total number of 1s in the array (onesCount).
- Use a sliding window of size onesCount to find the maximum number of 1s in any window of that size.
- Since the array is circular, extend the window size to 2 * n to handle wrapping.
- Calculate the current window sum and update it as the window slides.
- Track the maximum number of 1s found in any window (maxWindow).
- The minimum number of swaps needed is onesCount minus maxWindow.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**