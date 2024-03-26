### Approach:
- Iterate over both strings in reverse, ignoring characters removed by backspaces ('#').
- Compare corresponding valid characters from both strings. Continue this comparison until either of the strings ends.
​
### Complexity:
- **Time Complexity: `O(n)`** *=> where n is the maximum length between the two input strings*
- **Space Complexity: `O(1)`**