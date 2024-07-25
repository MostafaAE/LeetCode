### Approach:
- Create a mapping from each digit to its corresponding value using the provided mapping vector.
- For each number in the input nums, convert it to its mapped value using the digit-to-value mapping.
- Store the original numbers in a map where the key is the mapped value.
- Sort the map keys, and then reconstruct the sorted array using the original numbers stored in the map.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(n)`**, where n is the number of elements in nums.