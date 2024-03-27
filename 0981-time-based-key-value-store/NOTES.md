### Approach:
1. Utilize a hashmap that map each key to a vectror containing each timestamp and value pair.
2. To set a value we simply put it in the end of the key's corresponing vector.
3. To get a value we binary search for timestamp_prev <= timestamp in the corresponding vector and return the value of that timestamp.
​
### Complexity:
**Time Complexity:**
- `set O(1)`
- `get O(logn)`