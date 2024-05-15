### Approach:
- Use breadth-first search (BFS) to calculate the minimum manhattan distance for each cell to any thief in the grid.
- Binary search on all the possible safeness factors.
- Use breadth-first search (BFS) to find a valid path with a safeness factor greater than or equal to the current candidate.
​
### Complexity:
- **Time Complexity: `O(n^2 * log(max_distance))`**, where n is the size of the grid and max_distance is the maximum possible distance. The binary search takes O(log(max_distance)), and for each binary search iteration, BFS is performed, which takes O(n^2).
- **Space Complexity: `O(n^2)`**, for the distance matrix and the BFS queue.