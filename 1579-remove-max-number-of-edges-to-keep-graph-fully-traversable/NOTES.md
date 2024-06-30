### Approach:
- Use a UnionFind data structure to manage the connected components (forests).
- Separate the edges into three categories: Alice's exclusive, Bob's exclusive, and shared edges.
- Process the shared edges first to maximize the usage of these edges for both Alice and Bob.
- Process Alice's and Bob's exclusive edges separately to maintain their connectivity, and while doing so,determine the number of edges to remove and check if Alice and Bob can fully traverse the graph.
​
### Complexity:
- **Time Complexity: `O(E)`**, where E is the number of edges.
- **Space Complexity: `O(N + E)`**