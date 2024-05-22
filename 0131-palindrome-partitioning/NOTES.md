### Approach:
- Use a backtracking approach to find all possible palindrome partitions of the given string.
- At each position in the string, try to partition it by checking all possible substrings starting from that position.
- If a substring is a palindrome, add it to the current partition and recursively partition the rest of the string.
- When the end of the string is reached, add the current partition to the result.
​
### Complexity:
- **Time Complexity: `O(n * 2^n)`**, where n is the length of the string.
- **Space Complexity: `O(n)`**, for the recursive stack space.