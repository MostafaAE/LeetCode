### Approach:
- XOR all the numbers to get the XOR result of the two unique numbers.
- Find a bit that is set in the XOR result, which indicates a bit where the two unique numbers differ.
- Use this set bit to partition the numbers into two groups, one with the bit set and one with the bit not set.
- XOR all numbers in each group to get the two unique numbers.
- Note: We can easily solve it using a hashmap also but will be O(n) space complexity.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**