### Approach:
- Use a sliding window technique and maintain a multiset to store the elements of the current window. The multiset allows us to quickly get the minimum and maximum values in the window.
- Expand the window by moving the right pointer. If the condition (max - min <= limit) is violated, shrink the window by moving the left pointer.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(n)`**