### Approach:
- Use topological sorting (Kahn's algorithm) to process nodes in a way that ensures each node is processed only after all its ancestors.
- Use a set to store the ancestors of each node to avoid duplicates and to maintain sorted order.
- Build an adjacency list from the edges and compute the indegree of each node.
- Initialize a queue with nodes that have an indegree of 0 (i.e., nodes with no ancestors).
- Process each node, updating the ancestors of its neighbors and pushing neighbors with an indegree of 0 into the queue.
- Convert sets of ancestors to vectors for the final result.
​
### Complexity:
- **Time Complexity: `O(n^2logn + E)`**, where n is the number of nodes, and E is the number of edges.
- **Space Complexity: `O(n^2 + E)`**