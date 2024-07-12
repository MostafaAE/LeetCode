### Approach:
- If x > y, first remove all "ab" pairs, then remove "ba" pairs.
- If y >= x, first remove all "ba" pairs, then remove "ab" pairs.
- The removePairs function uses a stack to efficiently find and remove pairs from the string.
- Iterate through the string and use the stack to track potential start indices of pairs.
- If a matching pair is found, update the result with the given score and mark the characters in the string as used by setting them to '.'.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**