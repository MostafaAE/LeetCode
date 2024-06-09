### Approach:
- Use a prefix sum and a hash map to store the frequency of remainders when the prefix sum is divided by k.
- For each prefix sum, if the remainder is found in the hash map, it means there are subarrays ending at the current index whose sums are divisible by k. We add the count of this remainder from the hash map to our result.
​
### Complexity:
- **Time Complexity: `O(n)`** , where n is the number of elements in the nums array.
- **Space Complexity: `O(k)`**, because the hash map stores at most k remainders.