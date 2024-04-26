### Approach:
- Parse each email to remove any characters after '+' and remove '.' characters from the local name.
- Add the parsed email to a hashset to keep track of unique emails.
- Finally, return the size of the hashset, which represents the number of unique emails.
​
### Complexity:
- **Time Complexity: `O(N*L)`**
- **Space Complexity: `O(N)`**
*where N is the number of emails and L is the length of each email.*