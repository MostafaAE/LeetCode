### Approach:
- Construct a trie using the given dictionary of words.
- Insert each word from the dictionary into the trie.
- Split the input sentence into individual words.
- For each word, find the shortest prefix in the trie that matches the word.
- Join the processed words back into a single string.
​
### Complexity:
- **Time Complexity: `O(d.w + s.w)`**, where `d` is the dictionary length, `s` is the sentence length, and `w` is the average word length.
- **Space Complexity: `O(d.w + s.w)`**