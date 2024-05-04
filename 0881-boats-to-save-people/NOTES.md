### Approach:
- Sort the people array, and use a two-pointer approach to find the optimal pairings of people in boats.
- For each boat, start with the heaviest person and try to pick the lightest person if possible.
​
### Complexity:
- **Time Complexity: `O(n logn)`**, where n is the number of people.
- **Space Complexity: `O(1)`**