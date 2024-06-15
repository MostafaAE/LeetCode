### Approach:
- Use a map to group the projects by their capital requirements.
- Iterate through the projects and use a max-heap (priority queue) to keep track of the most profitable projects that can be afforded given the current capital.
- For each iteration (up to k times), add the most profitable project that can be afforded to the current capital and update the capital.
​
### Complexity:
- **Time Complexity: `O(nlogn + klogn)`**
- **Space Complexity: `O(n)`**