### Approach:
- Iterate through the array to calculate the degree of each number and store the first and last occurrence of it in a hashmap, and determine the highest degree.
- Iterate through the occurrences of numbers with the highest degree, calculating the length of each subarray and return the shortest of them.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**