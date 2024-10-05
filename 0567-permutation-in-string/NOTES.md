### Approach:
- Use a sliding window technique to check if any substring of `s2` is a permutation of `s1`.
- First, calculate the frequency of characters in `s1` and the first window of size `s1` in `s2`.
- Slide the window over `s2`, updating the character frequencies by removing the frequency of the outgoing character and adding the frequency of the incoming character.
- After each update, compare the frequency maps of `s1` and the current window in `s2` to check if they are the same.
​
### Complexity:
- **Time Complexity: `O(n)`**, where `n` is the size of `s2`.
- **Space Complexity: `O(1)`**