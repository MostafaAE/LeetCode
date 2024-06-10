### Approach:
- Use a counting sort to sort the heights.
- Count the occurrences of each height and store them in a frequency map.
- Reconstruct the sorted heights using the frequency map.
- Compare the original heights with the sorted heights to determine how many heights are out of place.
​
### Complexity:
- **Time Complexity: `O(n + k)`**, where n is the number of elements in the heights array and k is the maximum height value.
- **Space Complexity: `O(n)`**