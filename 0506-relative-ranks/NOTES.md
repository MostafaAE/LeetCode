### Approach:
- Use a priority queue (max heap) to store {score, index} pairs.
- Pop elements from the max heap one by one, assign ranks to the corresponding indices in the result vector.
​
### Complexity:
- **Time Complexity: `O(n logn)`**, where n is the number of scores
- **Space Complexity: `O(n)`**