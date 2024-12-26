### Approach:
1. Use Cycle Sort to rearrange the array such that each number is placed at its correct index.
- If a number is not at its correct index, swap it with the number at its correct index.
- Skip to the next index if the current number is already at its correct position.
2. Return the last two elements of the array after sorting as the "sneaky numbers".
​
### Complexity:
- **Time Complexity: `O(n)`** - Each number is swapped at most once during the sorting process.
- **Space Complexity: `O(1)`** - Sorting is done in-place without using additional data structures.