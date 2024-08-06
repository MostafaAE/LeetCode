### Approach:
- Count the frequency of each character in the given word using an unordered_map.
- Use a max heap (priority_queue) to store these frequencies in descending order.
- For each character frequency in the max heap, calculate the required key presses based on how many keys have been mapped (greedy).
- Return the total result after processing all frequencies.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**, number of distinct characters = 26 (constant).