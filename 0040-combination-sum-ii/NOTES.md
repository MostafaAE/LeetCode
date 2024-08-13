### Approach:
- Sort the candidates to facilitate the skipping of duplicates.
- Use backtracking to explore all possible combinations, starting from a given index.
- For each candidate, choose it if it doesn't duplicate the previous candidate at the same level.
- Recursively reduce the target and continue the search with the next candidates.
- If the target reaches zero, add the current combination to the result.
- After exploring a candidate, backtrack by removing it from the current combination.
​
### Complexity:
- **Time Complexity: `O(2^n)`**, where n is the number of candidates. This is because each candidate can either be included or excluded.
- **Space Complexity: `O(n)`**