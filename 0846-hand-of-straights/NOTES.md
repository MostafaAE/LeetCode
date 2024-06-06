## Approach:
- Check if the hand size is divisible by groupSize.
- Use a map to count the frequency of each card.
- Iterate through the map, forming groups of groupSize.
- For each card in the group, ensure that there are enough consecutive cards to form a valid group.
- Update the map accordingly, removing entries with zero counts.
​
### Complexity:
- **Time Complexity: `O(n logn)`**, where n is the number of cards in the hand.
- **Space Complexity: `O(n)`**