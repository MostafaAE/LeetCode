### Approach:
- Use the Floyd-Warshall algorithm to find the shortest paths between all pairs of cities by repeatedly relaxing the distances using intermediate cities.
- For each city, count the number of cities that are reachable within the distance threshold.
- Return the city with the smallest number of reachable cities within the distance threshold. If there are multiple such cities, return the one with the largest index.
​
### Complexity:
- **Time Complexity: `O(n^3)`**, due to the three nested loops in the Floyd-Warshall algorithm.
- **Space Complexity: `O(n^2)`**, for storing the distance matrix.