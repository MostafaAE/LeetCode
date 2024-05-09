### Approach:
- Sort the happiness array in non-ascending order to maximize the overall happiness sum.
- Iterate through the first k largest elements of the sorted array (greedy).
- For each element, add (happiness[i] - i) or 0 if it's negative.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(1)`**