### Approach:
- Use a counting sort algorithm.
- First, determine the minimum and maximum values in the input array.
- Create a count array to store the frequency of each number, adjusted by the minimum value.
- Fill the count array by iterating over the input array and incrementing the appropriate count.
- Reconstruct the sorted array from the count array.
​
### Complexity:
- **Time Complexity: `O(n + m)`**, where n is the number of elements in the input array, m is the max value in the array.
- **Space Complexity: `O(m)`**, where m is the max value in the array.