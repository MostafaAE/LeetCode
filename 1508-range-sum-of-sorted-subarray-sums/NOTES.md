### Approach:
- Create a new array to store all possible subarray sums.
- Iterate through each element of the nums array to compute all possible subarray sums.
- Sort the array of subarray sums.
- Compute the sum of elements from the 'left' to 'right' in the sorted array.
​
### Complexity:
- **Time Complexity: `O(n^2 logn)`**
- **Space Complexity: `O(n^2)`**