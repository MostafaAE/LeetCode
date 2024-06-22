### Approach:
- Use prefix sum to keep track of the number of odd numbers encountered so far.
- Use a hash map to store the frequency of each prefix sum.
- For each element in the array, update the current prefix sum and check if there exists a prefix sum that, when subtracted from the current prefix sum, equals k.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**