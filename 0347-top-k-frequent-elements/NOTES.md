### Approach:
- Utilize a hashmap to count the frequency of each number in the array.
- Then, use a max heap to store the numbers along with their frequencies.
- Pop the top k elements from the heap and return them as the result.
​
### Complexity:
- **Time Complexity: `O(n logn)`**
- **Space Complexity: `O(n)`**