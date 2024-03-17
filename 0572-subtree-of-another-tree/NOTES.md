### Approach:
For each node in root, check if subRoot is the same tree (dfs).\
We can also serialize or parenthesize each tree then match them.
​
### Complexity:
**Time Complexity: `O(n * m)`** *=> where n is the size of tree and m is the size of sub tree*\
**Space Complexity: `O(m)`** *=> auxiliary space for stack*