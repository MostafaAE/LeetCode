### Approach:
- Use binary search to find the minimum number of days needed to pick m bouquets.
- Define the search range from 0 to the maximum value in bloomDay.
- For each midpoint in the binary search: Check if it is possible to pick m bouquets in mid days. If possible, update the result and search in the left half; otherwise, search in the right half.
​
### Complexity:
- **Time Complexity: `O(n logD)`**, where N is the number of flowers and D is the highest value in the array bloomDay.
- **Space Complexity: `O(1)`**