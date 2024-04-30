### Approach:
- Maintain a bitmask to represent the parity of characters in the substring.
- Iterate through each character in the word and update the bitmask accordingly.
- Increment the result by the count of wonderful substrings found so far (count of the other prefixes whose masks differ from the current prefix mask by at most one bit).
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**