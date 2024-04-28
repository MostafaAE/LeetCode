### Approach:
- Iterate through each string in the input vector.
- For each string, sort its characters alphabetically. This will make anagrams have the same sorted representation.
- Use an unordered_map to store the sorted representation of each anagram and its corresponding index in the result vector.
- If the sorted representation is not found in the map, create a new entry in the result vector and map.
- Otherwise, append the string to the corresponding group in the result vector.
​
### Complexity:
- **Time Complexity: `O(m*n logn)`**
- **Space Complexity: `O(m*n)`** *where m is number of words, and n is average length of a word*