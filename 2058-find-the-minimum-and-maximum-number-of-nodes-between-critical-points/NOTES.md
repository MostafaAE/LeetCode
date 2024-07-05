### Approach:
- Traverse the linked list to identify critical points.
- A critical point is defined as a node where the value is either a local maximum or a local minimum.
- Track the indices of the first and previous critical points.
- Calculate the minimum and maximum distances between critical points.
- Return {-1, -1} if fewer than two critical points are found.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**