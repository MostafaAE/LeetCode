### Approach:
- Use a hash map to store the frequency of each element in arr2.
- Iterate through arr1 and count the frequency of elements that are in arr2, and collect elements not in arr2 separately.
- Sort the remaining elements not in arr2.
- Construct the result array by adding elements in the order defined by arr2 and then adding the sorted remaining elements.
​
### Complexity:
- **Time Complexity: `O(n logn + m)`**, where n is the size of `arr1` and m is the size of `arr2`.
- **Space Complexity: `O(n + m)`**, for the hash map and the remaining elements vector.