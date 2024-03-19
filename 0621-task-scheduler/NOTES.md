### Approach:
Count the frequency of each char, put all the frequencies in a max heap (lowest time, highest frequency)\
Each time pop an element from the heap and update its time and frequency and insert it again till the heap becomes empty.
​
### Complexity:
**Time Complexity: `O(n)`**\
**Space Complexity: `O(1)`**