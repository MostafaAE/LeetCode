### Approach:
- Use a sliding window to find the longest substring where the cost to change `s` to `t` is within maxCost.
- Iterate through the string with a right pointer to expand the window.
- Increment the current cost by the difference between the characters in `s` and `t` at the right pointer.
- If the current cost exceeds maxCost, move the left pointer to shrink the window until the current cost is within maxCost again.
- Keep track of the maximum length of the valid window.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**