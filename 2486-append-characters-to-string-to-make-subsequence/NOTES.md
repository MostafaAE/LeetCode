### Approach:
- Use a two-pointer technique to find the number of characters in `t` that cannot be matched in sequence in `s`.
- Initialize a pointer for `t` (matchedToIdx) to keep track of matched characters.
- Iterate over the string `s`, if the character at `s[i]` matches the character at `t[matchedToIdx]`, move the pointer `matchedToIdx` to the next character in `t`.
- At the end of the iteration, the number of unmatched characters in `t` is `t.size() - matchedToIdx`.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**