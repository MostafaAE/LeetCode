### Approach:
- Use a hash map to count the occurrences of each element in the `target` array and decrement the count for each element in the `arr` array.
- If the arrays can be made equal by reversing any number of sub-arrays, the counts of all elements should be zero after processing both arrays.
- Iterate through the `target` and `arr` arrays simultaneously, updating the count for each element in the hash map.
- Finally, check if all counts in the hash map are zero. If any count is not zero, return false. Otherwise, return true.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**