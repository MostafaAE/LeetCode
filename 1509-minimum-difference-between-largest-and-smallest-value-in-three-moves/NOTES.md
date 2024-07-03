### Approach:
- If the array size is less than or equal to 4, return 0 since we can remove all elements.
- Sort the array.
- The minimum difference is achieved by removing three elements in one of the following ways:
- Remove the three smallest elements.
- Remove the two smallest and the largest element.
- Remove the smallest and the two largest elements.
- Remove the three largest elements.
- Iterate through the array and calculate the minimum difference for these cases.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(1)`**