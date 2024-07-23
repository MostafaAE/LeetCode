### Approach:
- Use an unordered_map to count the frequency of each number in the input array.
- Use a map where the key is the frequency and the value is a set of numbers with that frequency.
- Iterate over the map and add each number to the result vector the number of times it appears.
​
### Complexity:
- **Time Complexity: `O(n logn)`**, where n is the number of elements in the input array.
- **Space Complexity: `O(n)`**