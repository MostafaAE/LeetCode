### Approach:
- Dynamic Programming with Memoization
- We use a 3D vector `memory` to store intermediate results to avoid redundant calculations, The 3D vector dimensions are `[n+1][2][3]` where: `n+1` represents the number of days from 0 to n, `2` represents the possible values for the count of absences (0 or 1), `3` represents the possible values for the count of consecutive lates (0, 1, or 2).
- The recursive function `countRecords` explores all possible attendance records by considering three choices at each step ('A' (Absent), 'L' (Late), 'P' (Present))
- Base cases handle the conditions where the sequence becomes invalid (too many absences or lates) or when all days have been processed.
- We use memoization to store results of subproblems to avoid recomputation.
​
### Complexity:
- **Time Complexity: `O(n)`**, Each state is visited at most once, and the number of states is `n * 2 * 3`.
- **Space Complexity: `O(n)`**, Space used by the memoization table and the recursion stack.