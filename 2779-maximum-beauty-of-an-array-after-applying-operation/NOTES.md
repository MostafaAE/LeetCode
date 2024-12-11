### Approach:
1. Sort the array `nums`.
2. Iterate through each element in the array:
- For each element `nums[i]`, find the first element greater than `nums[i] + 2*k` using `upper_bound`.
- Compute the beauty for this range as the distance between the current index and the iterator from `upper_bound`.
- Update the result to store the maximum beauty found so far.
3. Return the maximum beauty value.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(1)`**