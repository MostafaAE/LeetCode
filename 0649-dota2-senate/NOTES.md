### Approach:
- Maintain two queues, one for Radiants and one for Dires.
- Iterate through the senate string and enqueue each senator's index into the corresponding queue.
- Then, simulate the voting process until either all Radiants or all Dires are eliminated.
- During each iteration, compare the indices of the current Radiant and Dire senators:
- If the Radiant's index is less than the Dire's index, it means the Radiant senator has a higher priority to eliminate the next Dire senator. Therefore, push the Radiant's index to the Radiant queue with an incremented value representing its next appearance.
- If the Dire's index is less than the Radiant's index, it means the Dire senator has a higher priority to eliminate the next Radiant senator. Therefore, push the Dire's index to the Dire queue with an incremented value representing its next appearance.
- Finally, return the winner based on the remaining senators.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**