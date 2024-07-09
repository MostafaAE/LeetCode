### Approach:
- Initialize `nextIdleTime` to 0 and `totalWait` to 0.
- For each customer, calculate the time at which the server will serve them.
- Update `nextIdleTime` to the maximum of the customer's arrival time and the current `nextIdleTime` plus the customer's order time.
- Accumulate the waiting time for each customer, which is the difference between `nextIdleTime` and the customer's arrival time.
- Finally, return the average waiting time by dividing `totalWait` by the number of customers.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**