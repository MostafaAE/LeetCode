### Approach:
For each query, sort the element in range (l, r) and check if s[i+1] - s[i] == s[1] - s[0] for all valid i
​
### Complexity:
**Time Complexity: O(m*nlogn)** *where m is the number of queries and n is the number of elements*\
**Space Complexity: O(n)**