### Approach:
- Iterate through both version strings simultaneously.
- Extract the numbers between '.' characters and compare them.
- If a number in the first version is smaller than the corresponding number in the second version, return -1.
- If a number in the first version is larger than the corresponding number in the second version, return 1.
- If both versions are equal up to the end, return 0.
​
### Complexity:
- **Time Complexity: `O(max(n, m))`** , where n is the length of version1 and m is the length of version2.
- **Space Complexity: `O(1)`**