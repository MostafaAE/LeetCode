### Approach:
- Convert both sentences into vectors of words.
- If `s1` has more words than `s2`, swap them to always compare the smaller sentence with the larger one.
- Use two pointers, `start` and `end`, to check for matching words from the beginning and the end of the sentences.
- Continue moving `start` from the beginning as long as the words match, and `end` from the end as long as the words match.
- After both passes, if all words in `s1` can fit as a subsequence in `s2`, return true, otherwise return false.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, where `n` is the total number of words in s1 and `m` is the number of words in s2.
- **Space Complexity: `O(n + m)`**, for storing the words of both sentences in vectors.