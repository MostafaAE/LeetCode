### Approach:
- Use backtracking combined with memoization to explore all possible ways to split the string `s` into words found in `wordDict`.
- Create a set from `wordDict` for O(1) lookups.
- Use a helper function `split` to recursively build valid sentences.
- Use a hash map to store results of subproblems to avoid recomputation.
​
### Complexity:
- **Time Complexity: `O(2^N)`**, where N is the length of the string `s`. The `2^N` term accounts for all possible substrings.
- **Space Complexity: `O(2^N)`**