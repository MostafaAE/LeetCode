### Approach:
- Initialize a queue with all friends numbered from 1 to n.
- Simulate the process k-1 times and removing the k-th friend.
- Continue the process until only one friend is left.
- The last remaining friend is the winner.
​
### Complexity:
- **Time Complexity: `O(n*k)`**
- **Space Complexity: `O(h)`**