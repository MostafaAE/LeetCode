### Approach:
1. Precompute a `prefix` array where:
- `prefix[i]` stores the count of adjacent pairs of numbers with the same parity (even-even or odd-odd) up to index `i`.
2. Traverse the input `nums` array:
- If `nums[i]` and `nums[i-1]` have the same parity, increment `prefix[i]`.
- Otherwise, copy the value from `prefix[i-1]`.
3. For each query `[L, R]`:
- Check if `prefix[L] == prefix[R]`. If true, all pairs in the range `[L, R]` have the same parity.
4. Return a vector of booleans indicating the result for each query.
​
### Complexity:
- **Time Complexity: `O(n + q)`**
- **Space Complexity: `O(n)