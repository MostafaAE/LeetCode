### Approach:
- Each ith person before `k` will go in the queue `min(tickets[k], tickets[i]) times`.
- Each ith person after `k` will take go in the queue `min(tickets[k]-1, tickets[i]) times`.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**