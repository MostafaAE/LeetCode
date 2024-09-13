### Approach:
- Compute a prefix XOR array where `prefix[i]` represents the XOR of all elements from the start up to the index `i-1` in the original array.
- For each query, calculate the XOR of the subarray by using the difference between two prefix XOR values: `prefix[right + 1] ^ prefix[left]` gives the XOR from index `left` to `right`.
- Store the result for each query in a result vector and return it.
​
### Complexity:
- **Time Complexity: `O(n + 1)`**, where `n` is the size of the `arr` and `q` is the number of queries. The prefix XOR is calculated in O(n), and each query is processed in O(1).
- **Space Complexity: `O(n)`**, for storing the prefix XOR array.