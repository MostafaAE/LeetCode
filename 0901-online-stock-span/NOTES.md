### Approach:
- Maintain a monotonic decreasing stack to store pairs of (price, span).
- For each received price, if the new price is greater than or equal to the price on top of the stack, keep popping elements from the stack and update the current span.
- Push the new price and span pair onto the stack, and return the calculated span as the result.
​
### Complexity:
- **Time Complexity: `O(n)`**, on average `O(1)` for each call to `next()`.
- **Space Complexity: `O(n)`**, where n is the number of elements inserted so far.