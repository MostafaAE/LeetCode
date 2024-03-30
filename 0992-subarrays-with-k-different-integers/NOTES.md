### Approach:
Sliding window technique
1. Count the number of subarrays with at most k distinct integers.
2. Count the number of subarrays with at most (k-1) distinct integers.
3. Subtract 2 from 1 to get the number of subarrays with exactly k distinct integers.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**