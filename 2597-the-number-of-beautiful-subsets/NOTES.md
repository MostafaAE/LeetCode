### Approach:
- Use backtracking to generate all possible subsets of the given array.
- For each subset, check if it forms a beautiful subset based on the condition:
- A subset is beautiful if no two elements in the subset differ by exactly `k`.
- Count the number of beautiful subsets encountered during the backtracking process.
​
### Complexity:
- **Time Complexity: `O(2^n)`**, where n is the number of elements in the array (There are 2^n possible subsets).
- **Space Complexity: `O(n)`**