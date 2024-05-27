### Approach:
- Sort the array `nums` in ascending order.
- Iterate through the sorted array to determine the value of `x` such that exactly `x` numbers in the array are greater than or equal to `x`.
- For each element in the sorted array, check if the remaining number of elements is equal to or greater than the current element.
- If the above condition holds, and if `x` (the remaining number of elements) is not greater than the previous element, return `x`.
- If no such `x` is found, return -1.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(1)`**