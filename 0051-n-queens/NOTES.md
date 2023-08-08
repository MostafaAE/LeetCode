### Approach:
Backtracking.\
There are N columns but 2N-1 diagonals for normal and same for anti
r-c and r+c are simple formulas for the diagonals
​
The key idea is simply, recurse on rows
for each queen, try to put in each possible valid column
a valid column won't make it visible to added queens so far
colum (c), normal diagonal (r-c), anti-diagonal (r+c)
​
Complexity:
1- In first row, we have N valid choices
2- In second row, we have N-1 valid choices   (+ 1 trivial step )
3- In 3rd row, we have N-2 valid choices   (+ 2 trivial step )
​
So overall is O(N!)
In the base case, we use O(N^2) to create a single grid
If we have S solutions, then we also have O(S N^2), which is still a small factor!
​
### Complexity:
**Time Complexity: `O(N!)`**\
**Space Complexity: `O(N^2)`** *for temporary grid*