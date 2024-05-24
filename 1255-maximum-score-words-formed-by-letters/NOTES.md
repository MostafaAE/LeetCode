### Approach:
- Use backtracking to explore all possible combinations of words.
- For each combination, check if the word can be formed using the available letters.
- Calculate the score of each valid combination and keep track of the maximum score.
​
### Complexity:
- **Time Complexity: `O(2^N * L)`**, where N is the number of words and L is the average length of a word. This is because we explore all possible combinations of words (2^N) and for each combination, we might check each letter in the words (L).
- **Space Complexity: `O(N)`**, where N is the number of words (due to recursion depth).