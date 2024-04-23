### Approach:
- Iterate through the flowerbed, if the current position is empty, check if the previous and next positions are also empty.
- If both the previous and next positions are empty, plant a flower at the current position and move two steps forward.
- Return true if the count of planted flowers is equal to the required number of flowers (n).
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**