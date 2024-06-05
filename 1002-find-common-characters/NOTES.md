### Approach:
- Initialize a frequency map for the first word.
- Traverse each subsequent word, updating the frequency map to retain the minimum frequency of each character (common).
- Construct the result based on the minimum frequencies of each character.
​
### Complexity:
- **Time Complexity: `O(n * m)`**, where n is the number of words and m is the average length of a word.
- **Space Complexity: `O(1)`**