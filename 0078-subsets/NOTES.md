### Approach:
- Use a backtracking approach to generate all subsets of the given array.
- For each element in the array, we have two choices: include it in the current subset or exclude it.
- Recursively explore both choices and add the resulting subsets to the final result.
- When we reach the end of the array, add the current subset to the result.
​
### Complexity:
- **Time Complexity: `O(2^n * n)`**, where n is the number of elements in the array.
- **Space Complexity: `O(n)`**