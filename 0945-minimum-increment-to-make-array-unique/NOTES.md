### Approach:
- Use a frequency array to count occurrences of each value in the input array.
- Traverse the frequency array to handle duplicates:
- If a value occurs more than once, increment the next value(s) to make them unique.
- Accumulate the number of increments needed to make the values unique.
- Handle the maximum value in the frequency array to manage any remaining duplicates.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, where `n` is the length of the input array, and `m` is the max value in the input array.
- **Space Complexity: `O(m)`**