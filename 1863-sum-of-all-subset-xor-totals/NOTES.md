### Approach:
- Use a backtracking approach to explore all subsets of the given array.
- For each element in the array, we have two choices: include it in the current subset or exclude it.
- We maintain a running XOR result for the current subset being considered.
- When we reach the end of the array, we return the XOR result of the current subset.
- Sum up the results of all subsets to get the final answer.
​
### Complexity:
- **Time Complexity: `O(2^n)`**, where n is the number of elements in the array. (There are 2^n possible subsets)
- **Space Complexity: `O(n)`**, for the recursive stack space.