### Approach:
- Use an unordered map to store the count of each domain.
- Iterate through each count-domain pair, get the start index of each subdomain, and update the count for each subdomain.
- Finally, construct the result vector by combining the count and domain for each entry in the map.
​
### Complexity:
- **Time Complexity: `O(n * m)`**, where n is the number of count-domain pairs and m is the average length of a domain.
- **Space Complexity: `O(n * m)`**, for storing the count-domain pairs.