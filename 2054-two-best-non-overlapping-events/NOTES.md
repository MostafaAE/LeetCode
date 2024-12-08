### Approach:
1. Sort the events by their start time to process them in chronological order.
2. Use a priority queue to keep track of events that have ended. Each entry in the queue is a pair of `{end_time, value}`.
3. Traverse the sorted events:
- For the current event, remove events from the priority queue where the end time is less than the start time of the current event (these events cannot overlap with the current event).
- Update `maxVal` to store the highest value of non-overlapping events processed so far.
- Calculate the maximum sum of values by considering the current event's value and `maxVal`.
- Add the current event to the priority queue.
4. Return the maximum sum (`maxSum`) obtained during the traversal.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(n)`**