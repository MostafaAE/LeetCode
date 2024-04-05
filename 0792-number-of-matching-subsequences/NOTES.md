### Approach:
- Utilize a hashmap to map each char in `s` with its indicies.
- For each word in `words`, iterate over every character and check if it exists in `s` with an index greater than the last character index using binary search, and keep track of its index in `s`.
- If we reached the end of the word, then it's a matching subsequence, if we didn't find any char then it does not match.
​
### Complexity:
- **Time Complexity: `O(LNlog(M))`**
- **Space Complexity: `O(M)`** *where L is the length of max word in words, N is the lenghth of words, M is the length of s*