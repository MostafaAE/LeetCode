### Approach:
Utilize a variable-sized sliding window approach to find the number of subarrays with a product less than a given threshold, k. Initially, both left and right pointers are set to the beginning of the array. We continuously shift the right pointer to the right, multiplying the product by the value at the new position. If the product exceeds k, we shrink the window by shifting the left pointer to the right until the product falls below k.
​
### Complexity:
- **Time Complexity: `O(n)`**\
- **Space Complexity: `O(1)`**