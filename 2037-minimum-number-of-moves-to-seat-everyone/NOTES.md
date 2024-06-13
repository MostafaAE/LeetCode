### Approach:
- Sort both seats and students positions in ascending order using count sort.
- Greedily match each student to the nearest seat to him.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, where n is the size of seats and students arrays, and m is the max value in seats and students.
- **Space Complexity: `O(m)`**