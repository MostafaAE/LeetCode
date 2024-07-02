### Approach:
- If the size of `nums1` is greater than `nums2`, swap them to minimize space complexity.
- Use a hash map to count occurrences of each element in the smaller array.
- Iterate through the larger array and check if each element is in the hash map.
- If an element from the larger array is in the hash map and the count is greater than 0, add it to the result and decrease the count in the hash map.
​
### Complexity:
- **Time Complexity: `O(m + n)`**, where m is the size of nums1 and n is the size of nums2.
- **Space Complexity: `O(min(m, n))`**, We use a hash map to store counts of elements from the smaller array.