### Approach:
- Simulate the binary number reduction process step by step.
- Use a carry to handle the addition of 1 when the current bit is '1' or when there's a carry from a previous step.
- Iterate through the string from the last bit to the first bit (excluding the most significant bit).
- Depending on the value of the current bit and the carry, decide the number of steps required and update the carry.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(1)`**