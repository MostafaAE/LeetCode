### Approach:
- The importance of a node is proportional to its indegree (number of connections).
- To maximize the total importance, assign the highest importance to the node with the highest indegree.
- First, calculate the indegree of each node.
- Sort the indegree values in ascending order.
- Assign importances from 1 to n to the nodes in the order of their sorted indegree values.
- Calculate the total importance by summing the products of the assigned importance and the corresponding indegree value.
​
### Complexity:
- **Time Complexity: `O(E + nlogn)`**, where E is the number of edges (roads) and n is the number of nodes (cities).
- **Space Complexity: `O(n)`**, for storing the indegree array.