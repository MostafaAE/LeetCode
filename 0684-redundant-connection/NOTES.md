### Approach:
- Use UnionFind to detect cycles in an undirected graph.
- For each edge, if the two vertices are already in the same set, that edge is redundant.
- Otherwise, union the sets containing the two vertices.
​
### Complexity:
- **Time Complexity: `O(E)`**, where E is the number of edges.
- **Space Complexity: `O(n)`**, where n is the number of nodes.