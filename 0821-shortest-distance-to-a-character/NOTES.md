### Approach:
- First, store the indices of all occurrences of the character `c` in the string `s`.
- Then, iterate over the string and for each character, calculate the minimum distance to the nearest occurrence of `c`.
- Use two pointers (`prev` and `next`) to keep track of the nearest occurrences of `c` before and after the current index.
- Update these pointers as you move through the string.
​
### Complexity:
- **Time Complexity: `O(n)`**, where `n` is the length of the string `s`.
- **Space Complexity: `O(k)`**, where `k` is the number of occurrences of `c` in the string (to store their indices).