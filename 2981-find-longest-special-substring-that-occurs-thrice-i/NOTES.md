### Approach:
1. Append a non-alphabetic character (e.g., `'.'`) to the string `s` as a sentinel.
- This ensures the final sequence is processed without extra checks.
2. For each character `'a'` to `'z'`:
- Traverse the string and count the consecutive occurrences (`curLen`) of the current character.
- When a different character is encountered, update a `lenToCount` map:
- For each possible substring length `j` from `1` to `curLen`, increment the count of substrings of length `j`.
- If the count of substrings of length `j` reaches or exceeds `3`, update the result with the maximum valid `j`.
3. Reset `curLen` when the current character ends and repeat for the next character.
4. Return the largest substring length that occurs at least three times.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**