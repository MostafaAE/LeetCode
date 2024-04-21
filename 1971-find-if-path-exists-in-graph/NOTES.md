### Approach:
- Utilize a Union Find DS to represent the connectivity of vertices in the graph.
- Iterate through the edges vector and perform union operations to connect the vertices.
- After the unions, check if the source and destination vertices belong to the same set.
​
### Complexity:
- **Time Complexity: `O(V + E)`**
- **Space Complexity: `O(V)`**