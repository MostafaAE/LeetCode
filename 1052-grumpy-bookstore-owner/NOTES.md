### Approach:
- Calculate the number of customers that are satisfied when the owner is not grumpy.
- Use a sliding window to find the maximum number of additional satisfied customers that can be achieved by using the secret technique for 'minutes' duration.
- Slide the window across the grumpy array and calculate the sum of customers that can be satisfied in the window where the owner uses the secret technique.
- The final result is the sum of normally satisfied customers and the maximum additional satisfied customers achieved by the secret technique.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**