### Approach:
- Use the Floyd-Warshall algorithm to find the minimum conversion costs between all pairs of characters.
- Iterate through the source string and calculate the total minimum conversion cost to transform it into the target string.
- If a conversion is not possible (cost is OO), return -1.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, where n is the length of the source/target strings, and m is the length of original/changed vectors.
- **Space Complexity: `O(1)`**