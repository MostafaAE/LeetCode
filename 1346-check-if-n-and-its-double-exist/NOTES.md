### Approach:
1. Use an unordered set `targets` to store numbers from the array while iterating.
2. For each element in the array:
- Check if twice the current number (`arr[i] * 2`) exists in `targets`.
- If the current number is even, check if half of it (`arr[i] / 2`) exists in `targets`.
- If either condition is true, return `true`.
- Otherwise, add the current number to `targets`.
3. If the loop completes without finding a match, return `false`.
​
### Complexity:
- **Time Complexity: `O(n)`**
- **Space Complexity: `O(n)`**