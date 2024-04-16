### Approach:
- Count bulls (correct position digits) by comparing characters in the same position in secret and guess.
- For each out-of-position digit, track their frequency in both secret and guess using arrays.
- Calculate cows (out-of-position but existing digits) by finding the minimum frequency between the two arrays.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**