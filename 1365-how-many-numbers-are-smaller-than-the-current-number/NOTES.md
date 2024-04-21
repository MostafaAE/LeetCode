### Approach:
- Create a copy of the input vector to sort it.
- Use a hash map to store the smallest index of each unique number after sorting.
- Iterate through the original vector and push the corresponding smallest index from the hash map into the result vector.
​
### Complexity:
- **Time Complexity: `O(nlogn)`**
- **Space Complexity: `O(n)`**